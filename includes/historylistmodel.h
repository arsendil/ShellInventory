#ifndef HISTORYLISTMODEL_H
#define HISTORYLISTMODEL_H

#include "databasemanager.h"

#include <QAbstractListModel>
#include <QVector>

struct HistoryItem {
    QString action;
    QString type;
    int amount;
    QString time;
};

class HistoryListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        ActionRole = Qt::UserRole + 1,
        TypeRole,
        AmountRole,
        TimeRole
    };

    explicit HistoryListModel(QObject* parent = nullptr);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void addHistory(const HistoryItem& item);

private:
    QVector<HistoryItem> items_;

private:
    DatabaseManager dbManager_;
};

#endif // HISTORYLISTMODEL_H
