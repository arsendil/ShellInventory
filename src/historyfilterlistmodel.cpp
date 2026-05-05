#include "../includes/historyfilterlistmodel.h"
#include "historylistmodel.h"

HistoryFilterListModel::HistoryFilterListModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{

}

void
HistoryFilterListModel::filterHistoryByShellType(QString shellType) {
     filterString_ = shellType;
     invalidateFilter();
}

void
HistoryFilterListModel::setSourceModel(QAbstractItemModel *sourceModel) {
    QSortFilterProxyModel::setSourceModel(sourceModel);
}

bool
HistoryFilterListModel::filterAcceptsRow(int source_row,
                                              const QModelIndex &source_parent) const {
    if (!sourceModel()) return false;

    if (filterString_.isEmpty() || filterString_ == "All") return true;

    QModelIndex index = sourceModel()->index(source_row, 0, source_parent);
    QString type = index.data(HistoryListModel::TypeRole).toString();

    return (type == filterString_);
}
