//
// Created by kumkurum on 28.02.25.
//

#ifndef MODEL_H
#define MODEL_H
#include <QAbstractListModel>
#include <QUuid>
#include <QColor>

struct Item {
    QUuid _id;
    QString _name;
    QColor _color;
    int _index;
};

class Model: public QAbstractListModel {
    Q_OBJECT
public:
    Model(QObject* parent = nullptr);

    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

    enum Roles {
        NAME = Qt::UserRole+1,
        INDEX,
        COLOR,
        ID
    };

    Q_INVOKABLE void moveTo(int from, int to);

private:
    QList<Item> _storage;
};



#endif //MODEL_H
