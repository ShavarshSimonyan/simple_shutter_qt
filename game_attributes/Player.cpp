#include "Player.h"
#include "SpaceWars.h"

#include <QGraphicsScene>
#include <QTimer>

Player::Player (int id, const QString strSourcePath) : SpaceObject (strSourcePath, 5, 5, 50, id),
                                                       mBulletCount(0), mStopUpdates(false)
{}

Player::~Player()
{
    mStopUpdates = true;
}

void Player::keyPressEvent(QKeyEvent *ev)
{
    if (mStopUpdates)
        return;
    if (ev->key() == Qt::Key_Left || ev->key() == Qt::Key_A || ev->key() == Qt::Key_4)
    {
        if (this->x() - mMovementSize > scene()->sceneRect().bottomLeft().x())
            this->setPos (this->x() - mMovementSize, this->y());
    }
    else if (ev->key() == Qt::Key_Right || ev->key() == Qt::Key_D || ev->key() == Qt::Key_6)
    {
        if (this->x() + mMovementSize + this->pixmap().rect().width() < scene()->sceneRect().bottomRight().x())
            this->setPos (this->x() + mMovementSize, this->y());
    }
    if (ev->key() == Qt::Key_Space)
        emit spawnBullet();
}
