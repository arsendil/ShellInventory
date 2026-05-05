#ifndef INVENTORYSORTLISTMODEL_H
#define INVENTORYSORTLISTMODEL_H

#include <QSortFilterProxyModel>

class InventorySortListModel : public QSortFilterProxyModel {
    Q_OBJECT
public:
    explicit InventorySortListModel(QObject *parent = nullptr);

    Q_INVOKABLE void sortByRole(int role, Qt::SortOrder order = Qt::AscendingOrder);

public:
    void setSourceModel(QAbstractItemModel *sourceModel) override;

protected:
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override;

private:
    int sortColumn_ = 0;
};

#endif // INVENTORYSORTLISTMODEL_H
