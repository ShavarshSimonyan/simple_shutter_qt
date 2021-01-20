#include "TextViewer.h"
#include <QFont>
TextViewer::TextViewer(QString prefix, int data): mPrefix(prefix),
                                                  mData (data),
                                                  mFontSize(8)
{
    setPlainText(QString("%1: %2").arg(mPrefix).arg(mData));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Courier", mFontSize));
}



void TextViewer::updateData(int data)
{
    mData += data;
    setPlainText(QString("%1: %2").arg(mPrefix).arg(mData));
}

int TextViewer::getData() const
{
    return mData;
}

void TextViewer::setData(int data)
{
    mData = data;
}
