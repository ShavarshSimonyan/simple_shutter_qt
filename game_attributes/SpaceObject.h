#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include <QColor>
#include <QGraphicsRectItem>
#include <QString>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class SpaceObject: public QGraphicsPixmapItem
{
public:
    SpaceObject (const QString&strSourcePath = "", int height = 0,
                 int width = 0, int timeout = 0,
                 int id = 0, QGraphicsItem *parent = 0);
    SpaceObject (const SpaceObject &obj);
    virtual ~SpaceObject();

    virtual int getID () const;

    virtual void setScale (const float xScale = 1.0, const float yScale = 1.0);
protected:
    QTimer *mTimer;

    int mHeight;
    int mWidth;

    int mTimeOutTime;

    const int mID;

    const QString mSourcePath;

    QPixmap mPixmap;

    const int mMovementSize = 10;
};
#endif // SPACEOBJECT_H
