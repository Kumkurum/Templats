//
// Created by kumkurum on 28.02.25.
//

#include "Core.h"
#include "Model.h"

Core::Core(QObject *parent) :QObject(parent),
    _model{new Model{this}}
{

}
