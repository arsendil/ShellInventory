#include "inventorylistmodel.h"

InventoryListModel::InventoryListModel(QObject *parent)
    : QAbstractListModel(parent) {
    shells_.append({"60mm", 0, 0});
    shells_.append({"82mm", 0, 0});
    shells_.append({"100mm", 0, 0});
    shells_.append({"122mm", 0, 0});
    shells_.append({"152mm", 0, 0});
}

void
InventoryListModel::addShells(QString shellType, int amount) {
    for (int i = 0; i < shells_.size(); ++i) {
        if (shells_[i].shellType == shellType) {
            shells_[i].inStock += amount;
            emit dataChanged(index(i), index(i), {InStockRole});
            return;
        }
    }
}

bool
InventoryListModel::removeShells(QString shellType, int amount) {
    if (amount <= 0) {
        return false;
    }

    for (int i = 0; i < shells_.size(); ++i) {
        if (shells_[i].shellType == shellType) {
            if (shells_[i].inStock >= amount) {
                shells_[i].inStock -= amount;
                shells_[i].used    += amount;
                emit dataChanged(index(i), index(i), {InStockRole, UsedRole});
                return true;
            }
        }
    }

    return false;
}

int
InventoryListModel::rowCount(const QModelIndex &parent) const {
    return shells_.size();
}

QVariant
InventoryListModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case ShellTypeRole: return shells_.at(index.row()).shellType;
    case InStockRole:   return shells_.at(index.row()).inStock;
    case UsedRole:      return shells_.at(index.row()).used;
    }

    return QVariant();
}

QHash<int, QByteArray>
InventoryListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[ShellTypeRole] = "shellType";
    roles[InStockRole]   = "inStock";
    roles[UsedRole]      = "used";
    return roles;
}
