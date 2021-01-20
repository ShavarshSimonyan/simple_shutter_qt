#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QWidget>

#include "SpaceWars.h"
#include "settingsPage.h"
#include "userInfoPage.h"
#include "recordsPage.h"

class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MainWindow ();

    void resizeEvent(QResizeEvent *event);
public slots:
    void gameFinished (int);
private:

    SpaceWars *mSpaceWars;

    QHBoxLayout *mMainLayout;

    QMenuBar *mMenuBar;

    settingsPage *mSettingsPage;
    userInfoPage *mUserInfoPage;
    recordsMenu *mRecordsMenu;

    static const int mSceneWidth = 800;
    static const int mSceneHeight = 600;
    static const int mMenuBarHeight = 40;
};
#endif // MAINWINDOW_H
