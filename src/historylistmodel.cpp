#include "historylistmodel.h"

HistoryListModel::HistoryListModel(QObject* parent)
    : QAbstractListModel(parent)
{
    QList<HistoryItem> historyItems = dbManager_.getHistory();
    beginResetModel();
    items_.reserve(historyItems.size());
    for (const auto& item : historyItems) {
        items_.push_back(item);
    }
    endResetModel();
}

int
HistoryListModel::rowCount(const QModelIndex&) const
{
    return items_.size();
}

QVariant
HistoryListModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= items_.size())
        return {};

    const auto& item = items_[index.row()];

    switch (role) {
    case ActionRole: return item.action;
    case TypeRole: return item.type;
    case AmountRole: return item.amount;
    case TimeRole: return item.time;
    }

    return {};
}

QHash<int, QByteArray>
HistoryListModel::roleNames() const
{
    return {
        {ActionRole, "action"},
        {TypeRole, "type"},
        {AmountRole, "amount"},
        {TimeRole, "time"}
    };
}

void
HistoryListModel::addHistory(const HistoryItem& item)
{
    beginInsertRows(QModelIndex(), items_.size(), items_.size());
    items_.push_back(item);
    endInsertRows();
    dbManager_.insertHistory(item);
}
