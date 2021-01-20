#include "Enemy.h"
#include "SpaceWars.h"

#include <cstdlib>

#include <QGraphicsScene>
#include <QGraphicsItem>

Enemy::Enemy (int id, const int timeout, int sceneWidth,int playerWidth,
              const QString strSourcePath, QGraphicsItem* parent): SpaceObject (strSourcePath, 5, 5, timeout, id, parent),
                                                       mSceneWidth (sceneWidth),
                                                       mPlayerWidth (playerWidth)
{
    int x = std::rand() % mSceneWidth;
    if (x - pixmap().rect().width() < 0)
        x = 0;
    else if (x + pixmap().rect().width() > mSceneWidth)
        x = mSceneWidth - pixmap().rect().width() - mPlayerWidth / 2;
    setPos(x, 0);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(move()));
}

Enemy::Enemy (const Enemy& obj):QObject(obj.parent()),
                                SpaceObject(obj),
                                QSharedData(obj),
                                mSceneWidth(obj.mSceneWidth),
                                mPlayerWidth(obj.mPlayerWidth)
{}
void Enemy::diconnectSignals ()
{
    disconnect(mTimer, SIGNAL(timeout()), this, SLOT(move()));
}

Enemy::~Enemy ()
{
    diconnectSignals();
}

void Enemy::move()
{
    setPos (x(), y() + mMovementSize);
}
