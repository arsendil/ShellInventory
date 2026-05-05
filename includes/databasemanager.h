#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QVariantList>

struct HistoryItem;

class DatabaseManager {
public:
    explicit DatabaseManager();
    ~DatabaseManager();

    void insertHistory(const HistoryItem& historyItem);
    QList<HistoryItem> getHistory();

private:
    QSqlDatabase db;
    bool initializeDatabase();
};

#endif // DATABASEMANAGER_H
