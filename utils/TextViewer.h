#ifndef TEXTVIEWER_H
#define TEXTVIEWER_H

#include <QGraphicsTextItem>
#include <QString>
#include <QObject>
class TextViewer: public QGraphicsTextItem
{
public:
    TextViewer (QString prefix = "", int data = 0);
    void updateData (int diff = 1);
    int getData () const;
    void setData(int data);
private:
    QString mPrefix;
    int mData;
    int mFontSize;
};
#endif // TEXTVIEWER_H
