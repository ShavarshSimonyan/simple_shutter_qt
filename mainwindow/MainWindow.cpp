#include "MainWindow.h"
#include "../db_handling/dbData.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <unistd.h>

MainWindow::MainWindow ()
{
    // for debuging
    //std::cout << "pid = " << getpid() << std::endl;
    //std::this_thread::sleep_for(std::chrono::seconds(30));
    //////////////////////////////////////////////////////
    //setup mainwindow
    setWindowTitle("SpaceWars");
    setGeometry(0, 0, mSceneWidth, mSceneHeight + mMenuBarHeight);

    //setup spaceWars
    mSpaceWars  = new SpaceWars(this);
    mSpaceWars->setGeometry(0, mMenuBarHeight, width(), height() - mMenuBarHeight);
    mSpaceWars->move(0, mMenuBarHeight);

    //create main layout
    //mMainLayout = new QHBoxLayout(this);

    //setup menus
    mMenuBar = new QMenuBar (this);
    mMenuBar->setFixedSize(width(), mMenuBarHeight);
    mMenuBar->move(0, 0);
    QMenu *menu = new QMenu ("&Menu");

    //create settings page
    mSettingsPage = new settingsPage (this->width() / 4, this->height() / 4, this);
    mSettingsPage->hide();

    //create user info page
    mUserInfoPage = new userInfoPage (this->width() / 2, this->height() / 2, this);
    mUserInfoPage->move(this->width() / 2 - mUserInfoPage->width() / 2,
                        this->height() / 2 - mUserInfoPage->height() / 2);
    mUserInfoPage->hide();

    //create records page
    mRecordsMenu = new recordsMenu(this, this->width() / 2, this->height() / 3);
    mRecordsMenu->hide();

    //add submenus
    menu->addAction("&Start Game", mSpaceWars, SLOT (startGame()));
    menu->addAction("&Settings", mSettingsPage, SLOT(show()));
    menu->addAction("&Records", mRecordsMenu, SLOT(show()));
    menu->addAction("&Exit", this, SLOT (close()));
    mMenuBar->addMenu(menu);

    //add items to layout
    //mMainLayout->addWidget(mMenuBar);
    //mMainLayout->addWidget(mSpaceWars);

    //connect signals
    connect(mSettingsPage->getCombo(), SIGNAL(currentTextChanged(const QString &)), mSpaceWars, SLOT(setGameLevel(const QString &)));
    connect(mSettingsPage->getCombo(), SIGNAL(currentTextChanged(const QString &)), dbData::getInstance().data(), SLOT(setGameLevel(const QString &)));
    connect(mSpaceWars, SIGNAL(finishGame(int)), this, SLOT(gameFinished(int)));

    //set stored level value as default
    mSpaceWars->setGameLevel(QString("%1").arg(dbData::getInstance()->getGameLevel()));
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    QSize rect = size();
    rect.rheight() -= mMenuBar->height();
    mMenuBar->setFixedSize(rect.width(), mMenuBar->height());
    mSpaceWars->setGeometry(mSpaceWars->x(), mSpaceWars->y(), rect.width(), rect.height());
    mSpaceWars->resizeWindow(rect);
}

void MainWindow::gameFinished (int score)
{
    mUserInfoPage->show();
    mUserInfoPage->setCurrentScore(score);
}
