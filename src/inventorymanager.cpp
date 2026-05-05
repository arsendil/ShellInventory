#include <inventorymanager.h>
#include <QDateTime>

InventoryManager::InventoryManager(QObject *parent)
    : QObject{parent} {
    historyFilterModel_.setSourceModel(&historyModel_);
    inventorySortListModel_.setSourceModel(&inventoryListModel_);
}

InventorySortListModel*
InventoryManager::inventorySortListModel() {
    return &inventorySortListModel_;
}

HistoryFilterListModel*
InventoryManager::historyFilterModel() {
    return &historyFilterModel_;
}

void
InventoryManager::addShells(QString shellType, int amount) {
    inventoryListModel_.addShells(shellType, amount);

    addHistory("Added", shellType, amount);
}

bool
InventoryManager::removeShells(QString shellType, int amount) {
    bool ok = inventoryListModel_.removeShells(shellType, amount);
    if (!ok) {
        return false;
    }
    addHistory("Removed", shellType, amount);
    return true;
}

void
InventoryManager::addHistory(QString action, QString type, int amount) {
    HistoryItem item;
    item.action = action;
    item.type = type;
    item.amount = amount;
    item.time = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    historyModel_.addHistory(item);
}
