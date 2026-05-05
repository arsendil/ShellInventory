#ifndef HISTORYFILTERLISTMODEL_H
#define HISTORYFILTERLISTMODEL_H

#include <QSortFilterProxyModel>

class HistoryFilterListModel : public QSortFilterProxyModel {
    Q_OBJECT
public:
    explicit HistoryFilterListModel(QObject *parent = nullptr);

    Q_INVOKABLE void filterHistoryByShellType(QString shellType);

public:
    void setSourceModel(QAbstractItemModel *sourceModel) override;

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

private:
    QString filterString_;
};

#endif // HISTORYFILTERLISTMODEL_H
