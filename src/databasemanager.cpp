#include "databasemanager.h"
#include "historylistmodel.h"

DatabaseManager::DatabaseManager() {
    if (!initializeDatabase()) {
        qDebug() << "Failed to initialize the database!";
    }
}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
    }
}

void
DatabaseManager::insertHistory(const HistoryItem &historyItem) {
    QSqlQuery query;
    query.prepare("INSERT INTO inventory (date_time, action_type, shell_type, quantity) VALUES (?, ?, ?, ?)");
    query.addBindValue(historyItem.time);
    query.addBindValue(historyItem.action);
    query.addBindValue(historyItem.type);
    query.addBindValue(historyItem.amount);

    if (!query.exec()) {
        qDebug() << "Error: Failed to insert history record:" << query.lastError().text();
    }
}

QList<HistoryItem>
DatabaseManager::getHistory() {
    QList<HistoryItem> historyList;
    QSqlQuery query("SELECT date_time, action_type, shell_type, quantity FROM inventory ORDER BY date_time DESC");

    while (query.next()) {
        HistoryItem item;
        item.time = query.value(0).toString();
        item.action = query.value(1).toString();
        item.type = query.value(2).toString();
        item.amount = query.value(3).toInt();
        historyList.append(item);
    }

    return historyList;
}

bool
DatabaseManager::initializeDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("shell_inventory.db");

    if (!db.open()) {
        qDebug() << "Error: Unable to open database:" << db.lastError().text();
        return false;
    } else {
        qDebug() << "Database opened successfully. File path:" << db.databaseName();
    }

    QSqlQuery query;
    QString createTableQuery = R"(
        CREATE TABLE IF NOT EXISTS inventory (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            date_time TEXT,
            action_type TEXT,
            shell_type TEXT,
            quantity INTEGER
        )
    )";

    if (!query.exec(createTableQuery)) {
        qDebug() << "Error: Failed to create table:" << query.lastError().text();
        return false;
    }
    return true;
}
