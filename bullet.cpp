#include "Bullet.h"
#include "Enemy.h"
#include "SpaceWars.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>

bullet::bullet (int id, const int timeout, const QString strSourcePath, QGraphicsItem *parent): SpaceObject(strSourcePath, 5, 5, timeout, id, parent)
{
    connect(mTimer, SIGNAL(timeout()), this, SLOT(move()));
}

bullet::bullet (const bullet &obj):QObject(obj.parent()),
                                    SpaceObject(obj),
                                    QSharedData(obj)
{}

bullet::~bullet ()
{
    disconnect(mTimer, SIGNAL(timeout()), this, SLOT(move()));
}

void bullet::move()
{
    QList <QGraphicsItem *> items = collidingItems();
    for (int i = 0, n = items.size(); i < n; ++i)
    {
        Enemy *enemy = nullptr;
        if ((enemy = dynamic_cast<Enemy*>(items[i])))
        {
            emit increaseScore();
            emit removeEnemy(enemy->getID());
            emit removeBullet(getID());
            return;
        }
    }

    if (y() + pixmap().rect().height() < 0)
    {
        emit removeBullet(getID());
        return;
    }
    setPos (x(), y() - mMovementSize);
}
