#ifndef MYRECT_H
#define MYRECT_H

#include "SpaceObject.h"
#include "Bullet.h"

#include <QKeyEvent>
#include <QObject>
#include <QHash>

class Player :public QObject, public SpaceObject
{
    Q_OBJECT
public:
    Player (int id = 0, const QString strSourcePath = ":/images/resources/gun_tr.png");
    ~Player ();
    void keyPressEvent(QKeyEvent *ev);

signals:
    void spawnBullet();

private:

    int mBulletCount;

    bool mStopUpdates;
};

#endif // MYRECT_H
