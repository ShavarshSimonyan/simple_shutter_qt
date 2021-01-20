#include "SpaceObject.h"
#include <QBrush>
#include <QPainter>
SpaceObject::SpaceObject (const QString &strSourcePath, int height,
                          int width, int timeout,
                          int id, QGraphicsItem *parent):QGraphicsPixmapItem(parent),
                                                         mTimer (new QTimer ()),
                                                         mHeight (height),
                                                         mWidth (width),
                                                         mTimeOutTime(timeout),
                                                         mID(id),
                                                         mSourcePath(strSourcePath),
                                                         mPixmap(mSourcePath)
{
    setPixmap(mPixmap);
    mTimer->start (mTimeOutTime);
}
SpaceObject::SpaceObject (const SpaceObject &obj):QGraphicsPixmapItem(obj.parentItem()),
                                                  mTimer (new QTimer ()),
                                                  mHeight (obj.mHeight),
                                                  mWidth (obj.mWidth),
                                                  mTimeOutTime(obj.mTimeOutTime),
                                                  mID(obj.mID),
                                                  mSourcePath(obj.mSourcePath),
                                                  mPixmap(obj.mPixmap)
{
    setPixmap(mPixmap);
    mTimer->start (mTimeOutTime);
}

SpaceObject::~SpaceObject ()
{}

int SpaceObject::getID() const
{
    return mID;
}

void SpaceObject::setScale (const float xScale, const float yScale)
{
    QPixmap pixmap (mPixmap);
    pixmap.scaled(pixmap.rect().width() * xScale, pixmap.rect().height() * yScale);
    setPixmap(pixmap);
}
