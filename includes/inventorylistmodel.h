#ifndef INVENTORYLISTMODEL_H
#define INVENTORYLISTMODEL_H

#include <QAbstractListModel>
#include <qqmlintegration.h>

struct ShellData {
    QString shellType;
    int inStock;
    int used;
};

class InventoryListModel : public QAbstractListModel {
    Q_OBJECT
    QML_ELEMENT
public:
    enum ShellRoles {
        ShellTypeRole = Qt::UserRole + 1,
        InStockRole,
        UsedRole
    };
    Q_ENUM(ShellRoles)

    explicit InventoryListModel(QObject *parent = nullptr);

public:
    void addShells(QString shellType, int amount);
    bool removeShells(QString shellType, int amount);

public:
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    QVector<ShellData> shells_;

};

#endif // INVENTORYLISTMODEL_H
