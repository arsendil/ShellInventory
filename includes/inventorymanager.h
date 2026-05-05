#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include "historyfilterlistmodel.h"
#include "historylistmodel.h"
#include "inventorylistmodel.h"
#include "inventorysortlistmodel.h"

#include <QObject>
#include <qqmlintegration.h>

class InventoryManager : public QObject {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(InventorySortListModel* inventorySortListModel READ inventorySortListModel CONSTANT)
    Q_PROPERTY(HistoryFilterListModel* historyFilterModel READ historyFilterModel CONSTANT)

public:
    explicit InventoryManager(QObject *parent = nullptr);

    InventorySortListModel* inventorySortListModel();
    HistoryFilterListModel* historyFilterModel();

    Q_INVOKABLE void addShells(QString shellType, int amount);
    Q_INVOKABLE bool removeShells(QString shellType, int amount);

private:
    void addHistory(QString action, QString type, int amount);

    InventoryListModel inventoryListModel_;
    InventorySortListModel inventorySortListModel_;
    HistoryListModel   historyModel_;
    HistoryFilterListModel historyFilterModel_;
};

#endif // INVENTORYMANAGER_H
