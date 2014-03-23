#ifndef ROBJECT_H
#define ROBJECT_H

#include <QObject>
#include "bomb.h"

class RObject : public QObject
{
    Q_OBJECT
public slots:
    void boom();
};

#endif // ROBJECT_H
