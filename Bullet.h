#ifndef BULLET_H
#define BULLET_H

#include "SpaceObject.h"

#include <QObject>
#include <QGraphicsItem>

class bullet: public QObject, public SpaceObject, public QSharedData
{
    Q_OBJECT
public:
    bullet (int id, const int timeout, const QString strSourcePath = ":/images/resources/bullet_tr.png", QGraphicsItem *parent = 0);
    bullet (const bullet &);
    ~bullet ();
signals:
    void increaseScore();
    void removeEnemy (int);
    void removeBullet (int);
public slots:
    void move ();
};

#endif // BULLET_H
