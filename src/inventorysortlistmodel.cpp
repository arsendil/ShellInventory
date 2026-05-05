#include "../includes/inventorysortlistmodel.h"

InventorySortListModel::InventorySortListModel(QObject *parent)
    : QSortFilterProxyModel{parent} {}

void
InventorySortListModel::sortByRole(int role, Qt::SortOrder order) {
    setSortRole(role);
    sort(0, order);
}

void
InventorySortListModel::setSourceModel(QAbstractItemModel *sourceModel) {
    QSortFilterProxyModel::setSourceModel(sourceModel);
}

bool
InventorySortListModel::lessThan(const QModelIndex &left,
                                      const QModelIndex &right) const {
    QVariant leftData = sourceModel()->data(left, sortRole());
    QVariant rightData = sourceModel()->data(right, sortRole());

    if (leftData.typeId() == QMetaType::QString) {
        QStringList shellOrder = {"60mm", "82mm", "100mm", "122mm", "152mm"};
        int leftIndex = shellOrder.indexOf(leftData.toString());
        int rightIndex = shellOrder.indexOf(rightData.toString());
        return leftIndex < rightIndex;
    }

    return leftData.toDouble() > rightData.toDouble();
}
