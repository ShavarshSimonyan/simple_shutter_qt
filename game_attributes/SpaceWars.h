#ifndef SPACEWARS_H
#define SPACEWARS_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDialog>
#include <QTimer>
#include <QSharedPointer>
#include <QScopedPointer>
#include <QHash>
#include <QMediaPlayer>
#include <QMenuBar>

#include "Enemy.h"
#include "Player.h"
#include "../utils/TextViewer.h"

class SpaceWars : public QWidget
{
    Q_OBJECT
public:
    SpaceWars (QWidget *parent = nullptr);
    ~SpaceWars ();
    void resizeWindow(const QSize &newSize);
public slots:
    void startGame ();

    void checkBulletsState ();

    void checkEnemyStatus ();

    void spawnEnemies ();

    void updateScore ();

    void updateLives ();

    void removeEnemyObject (int);

    void removeBullet (int id);

    void spawnBullet();

    void setGameLevel (const QString &);
signals:
    void finishGame (int);
private:
    SpaceWars ();

    void clearSceneObjects ();

    void diconnectAllSignals ();
private:
    int mSpaceObjectCount;


    QGraphicsScene mScene;

    QGraphicsView mView;

    Player mPlayer;

    QTimer mSpawnTimer;
    QTimer mCheckEnemyStatusTimer;
    QTimer mCheckBulletsState;

    TextViewer mScore;
    TextViewer mLives;

    QHash <int, QSharedPointer <Enemy>> mEnemies;
    QHash <int, QSharedPointer <bullet>> mBullets;

    bool mQuit;

    QMediaPlayer mMediaPlayer;

    //current level difficulty of game
    int mCurrentLevel;

    //score and live positions
    static const int mScoreInitialPosX = 0;
    static const int mScoreInitialPosY = 0;
    static const int mLivesDistanceY = 15;

    //number of game levels
    static const int numOfLevels = 3;

    // timeout values for each game level
    static const int spawnTimeout[numOfLevels];
    static const int bulletMoveTimeout [numOfLevels];
    static const int enemyMoveTimeout [numOfLevels] ;

    //
    static const int mRemoveTimeout = 150;
    static const int mSpaceObjectTimeout = 300;

    //default live of player
    static const int mDefaultLives = 2;
};
#endif // SPACEWARS_H
