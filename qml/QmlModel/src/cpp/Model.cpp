//
// Created by kumkurum on 28.02.25.
//

#include "Model.h"
#include <QDebug>


Model::Model(QObject *parent) {
    for (auto i{0}; i < 30; ++i)
        _storage.append({QUuid::createUuid(), "item_", QColor(qrand() % 255, qrand() % 255, qrand() % 255), i});
}

int Model::rowCount(const QModelIndex &parent) const {
    return static_cast<int>(_storage.size());
}

QVariant Model::data(const QModelIndex &index, int role) const {
    if (index.row() < 0 || index.row() >= _storage.size())
        return {};
    auto item = _storage.at(index.row());
    switch (role) {
        case Roles::ID:
            return item._id;
        case Roles::NAME:
            return item._name;
        case Roles::INDEX:
            return item._index;
        case Roles::COLOR:
            return item._color;
        default:
            return {};
    }
}

QHash<int, QByteArray> Model::roleNames() const {
    return {
        {Roles::ID, "_id"},
        {Roles::NAME, "_name"},
        {Roles::INDEX, "_index"},
        {Roles::COLOR, "_color"}
    };
}

void Model::moveTo(int from, int to) {
    qDebug() << "MOVE FROM " << from << " TO " << to << "SIZE " << _storage.size();
    if (from == to)
        return;
    if (from < to) {
            beginMoveRows({}, from, from, {}, to+1);
        if (to + 1 == _storage.size()) {
            _storage.move(from, to );
        } else {
            _storage.move(from, to + 1);
        }
    } else {
        beginMoveRows({}, from, from, {}, to);
        _storage.move(from, to);
    }
    endMoveRows();
}
