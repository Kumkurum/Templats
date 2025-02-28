//
// Created by kumkurum on 28.02.25.
//

#ifndef CORE_H
#define CORE_H

#include <QObject>
#include <QAbstractListModel>


class Core : public QObject {
    Q_OBJECT
Q_PROPERTY(QAbstractListModel* model MEMBER _model CONSTANT)
public:
    explicit Core(QObject *parent = nullptr);
private:
    QAbstractListModel *_model;
};


#endif //CORE_H
