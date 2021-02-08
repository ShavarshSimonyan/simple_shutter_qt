//
#include "settingsPage.h"
#include "../db_handling/dbData.h"
#include <QDebug>
settingsPage::settingsPage (int width,
                            int height,
                            QWidget *parent) : QWidget(parent),
                                               mWidth(width),
                                               mHeight(height)
{
    //set window size
    setFixedSize(mWidth, mHeight);

    //set window title
    mMenuTitle = new QLabel ("Settings", this);
    mMenuTitle->setFixedWidth(this->width());
    mMenuTitle->setAlignment(Qt::AlignCenter);

    //create the layout
    mMainLayout = new QVBoxLayout ();

    //create close button
    mCloseButton = new QPushButton (this);
    mCloseButton->setText("Close");
    //mCloseButton->setFixedSize(15, 5);
    connect(mCloseButton, SIGNAL(pressed()), this, SLOT(hide()));

    //create combo for setting game level
    mGameLevel = new QComboBox (this);
    mGameLevel->addItem("1");
    mGameLevel->addItem("2");
    mGameLevel->addItem("3");

    //set stored value
    int val = dbData::getInstance()->getGameLevel() - 1;
    mGameLevel->setCurrentIndex(val);

    //create grid layout
    QGridLayout *pGridLayout = new QGridLayout (this);

    //add game level combo to main layout
    QLabel *gameLabel = new QLabel ("Game level: ", this);
    pGridLayout->addWidget(gameLabel, 0, 0);
    pGridLayout->addWidget(mGameLevel, 0, 1);

    mMainLayout->addLayout(pGridLayout);

    //move close button to bottom right corner
    mCloseButton->move(this->width() - mCloseButton->width(), this->height() - mCloseButton->height());

    //set background color
    QPalette pal;
    pal.setColor(QPalette::Background, Qt::gray);
    setAutoFillBackground(true);
    setPalette(pal);
}

QComboBox* settingsPage::getCombo()
{
    return mGameLevel;
}
