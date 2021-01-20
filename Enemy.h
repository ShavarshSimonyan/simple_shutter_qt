#ifndef ENEMY_H
#define ENEMY_H

#include "SpaceObject.h"
#include <QObject>
#include <QSharedData>

class Enemy: public QObject, public SpaceObject, public QSharedData
{
    Q_OBJECT
public:
    Enemy (int id, const int timeout, int sceneWidth = 0, int playerWidth = 0,
           const QString strSourcePath = ":/images/resources/enemy_tr.png", QGraphicsItem* parent = 0);
    Enemy (const Enemy& obj);
    ~Enemy ();

    void diconnectSignals ();
public slots:
    void move ();
private:
    const int mSceneWidth;
    const int mPlayerWidth;
};
#endif // ENEMY_H
