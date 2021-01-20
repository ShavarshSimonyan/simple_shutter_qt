#include "SpaceWars.h"
#include "Bullet.h"

#include <QMessageBox>

#include <future>

// initializing timeout values for each game level
const int SpaceWars::spawnTimeout[numOfLevels] = {3000, 2500, 1500};
const int SpaceWars::bulletMoveTimeout [numOfLevels] = {150, 75, 30};
const int SpaceWars::enemyMoveTimeout [numOfLevels] = {800, 400, 200};

SpaceWars::SpaceWars (QWidget *parent): QWidget(parent),
                                        mSpaceObjectCount(0),
                                        mScene (this),
                                        mView(&mScene, this),
                                        mPlayer(++mSpaceObjectCount),
                                        mScore("Score", 0),
                                        mLives("Lives", mDefaultLives),
                                        mQuit(false),
                                        mCurrentLevel(0)
{
    //setup media player
    mMediaPlayer.setMedia(QUrl("qrc:/sounds/resources/bullet.wav"));

    //adding player to scene
    mScene.addItem(&mPlayer);

    //add score to scene
    mScene.addItem(&mScore);
    mScore.setPos(mScoreInitialPosX, mScoreInitialPosY);

    //add Lives to scene
    mScene.addItem(&mLives);
    mLives.setPos(mScore.x(), mScore.y() + mLivesDistanceY);

    //set scene color
    mScene.setBackgroundBrush(Qt::yellow);

    // make rect focusable
    mPlayer.setFlag(QGraphicsItem::ItemIsFocusable);
    mPlayer.setFocus();

    //setup view
    mView.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mView.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

SpaceWars::~SpaceWars()
{
    mQuit = true;
    diconnectAllSignals();
    clearSceneObjects();
}

void SpaceWars::spawnBullet()
{
    if (mQuit)
        return;
    QSharedPointer <bullet> b (new bullet (++mSpaceObjectCount, bulletMoveTimeout[mCurrentLevel]));
    connect(b.data(), SIGNAL(removeBullet(int)), this, SLOT(removeBullet(int)));
    connect(b.data(), SIGNAL(removeEnemy(int)), this, SLOT(removeEnemyObject(int)));
    connect(b.data(), SIGNAL(increaseScore()), this, SLOT(updateScore()));
    b->setPos(mPlayer.x() + mPlayer.pixmap().rect().width() / 2 - b->pixmap().rect().width() / 2, mPlayer.y () + mPlayer.pixmap().rect().height());
    mScene.addItem (b.data());
    mBullets.insert(b->getID(), b);

    if (mMediaPlayer.state() == QMediaPlayer::PlayingState)
        mMediaPlayer.setPosition(0);
    else if (mMediaPlayer.state() == QMediaPlayer::StoppedState)
        mMediaPlayer.play();
}

void SpaceWars::startGame ()
{
    mQuit = false;
    mScore.setData(0);
    mLives.setData(mDefaultLives);

    //setup timer for creating enemies
    connect(&mSpawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
    mSpawnTimer.start (spawnTimeout[mCurrentLevel]);

    //setup timer for deleting enemies
    connect(&mCheckEnemyStatusTimer, SIGNAL(timeout()), this, SLOT(checkEnemyStatus()));
    mCheckEnemyStatusTimer.start(mSpaceObjectTimeout);

    //setup timer for adjusting bullet coordinates
    connect(&mCheckBulletsState, SIGNAL(timeout()), this, SLOT(checkBulletsState()));
    mCheckBulletsState.start(mSpaceObjectTimeout);

    //setup bullet spawning
    connect(&mPlayer, SIGNAL(spawnBullet()), this, SLOT(spawnBullet()));

    //set view size
    mView.setFixedSize(size() + QSize(2,2));
    mScene.setSceneRect(0, 0, mView.width(), mView.height());
    //set player in the middle
    mPlayer.setPos(mView.width() / 2 - mPlayer.pixmap().rect().width() / 2, mView.height() - mPlayer.pixmap().rect().height());

    // show the view;
    mView.show();
}
void SpaceWars::resizeWindow(const QSize &newSize)
{
    mView.setFixedSize(newSize + QSize(2,2));
    mScene.setSceneRect(0, 0, mView.width(), mView.height());
    mView.mapToScene(mView.viewport()->rect().center()) ;
    mPlayer.setPos(mView.width() / 2 - mPlayer.pixmap().rect().width() / 2, mView.height() - mPlayer.pixmap().rect().height());
    mScene.update();
}
void  SpaceWars::spawnEnemies ()
{
    if (mQuit)
        return;
    QSharedPointer<Enemy> enemy (new Enemy (++mSpaceObjectCount, enemyMoveTimeout[mCurrentLevel], mView.width(), mPlayer.pixmap().rect().width()));
    mEnemies.insert(enemy->getID(), enemy);
    mScene.addItem(enemy.data());
}

void SpaceWars::updateScore ()
{
    if (mQuit)
        return;
    mScore.updateData(1);
}
void SpaceWars::clearSceneObjects()
{
    QList<QGraphicsItem*> allGraphicsItems = mScene.items();
    for(int i = 0; i < allGraphicsItems.size(); i++)
    {
        QGraphicsItem *graphicItem = allGraphicsItems[i];
        Enemy *enemy = nullptr;
        bullet *b = nullptr;
        if ((enemy = dynamic_cast<Enemy*>(graphicItem)))
            removeEnemyObject(enemy->getID());
        else if ((b = dynamic_cast<bullet*>(graphicItem)))
            removeBullet(b->getID());
    }
    mScene.update();
}

void SpaceWars::diconnectAllSignals()
{
    disconnect(&mPlayer, SIGNAL(spawnBullet()), this, SLOT(spawnBullet()));
    disconnect(&mSpawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemies()));
    disconnect(&mCheckEnemyStatusTimer, SIGNAL(timeout()), this, SLOT(checkEnemyStatus()));
    disconnect(this, SLOT(updateLives()));
    disconnect(this, SLOT(updateScore()));
    disconnect(this, SLOT(removeEnemyObject(int)));
}

void SpaceWars::updateLives()
{
    if (mQuit)
        return;
    mLives.updateData(-1);
    if ((mLives.getData() == 0))
    {
        mQuit = true;
        diconnectAllSignals();
        std::future<void> fut = std::async(std::launch::async, &SpaceWars::clearSceneObjects, this);
        QMessageBox msg(this);
        msg.setText(QString("%1\nYour score is %2").arg("You lost").arg(mScore.getData()));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();

        fut.get();

        emit finishGame(mScore.getData());

        return;
    }
}

void SpaceWars::removeEnemyObject (int id)
{
    auto it = mEnemies.find(id);
    if (it != mEnemies.end())
    {
        auto enemy = it.value();
        mScene.removeItem(enemy.data());
        mEnemies.erase(it);
    }
}

void SpaceWars::removeBullet(int id)
{
    auto it = mBullets.find(id);
    if (it != mBullets.end())
    {
        auto b = it.value();
        disconnect(b.data(), SIGNAL(removeBullet(int)), this, SLOT(removeBullet(int)));
        mScene.removeItem(b.data());
        mBullets.erase(it);
    }
}

void SpaceWars::checkEnemyStatus ()
{
    if (mQuit)
        return;
    for (auto it = mEnemies.begin(); it != mEnemies.end();)
    {
        if (mQuit)
            return;
        auto enemy = it.value();
        if (enemy->y() >= mScene.sceneRect().height() - enemy->pixmap().rect().height())
        {
            ++it;
            updateLives ();
            removeEnemyObject (enemy->getID());
            continue;
        }
        if (enemy->x() < mView.sceneRect().bottomLeft().x())
        {
            enemy->setPos(mView.sceneRect().bottomLeft().x(), enemy->y());
            continue;
        }
        if (enemy->x() > mScene.sceneRect().topRight().x() - enemy->pixmap().rect().width())
        {
            enemy->setPos(mScene.sceneRect().topRight().x() - enemy->pixmap().rect().width(), enemy->y());
            continue;
        }
        ++it;
    }
}

void SpaceWars::checkBulletsState ()
{
    if (mQuit)
        return;
    for (auto it = mBullets.begin(); it != mBullets.end(); ++it)
    {
        if (mQuit)
            return;
        auto b = it.value();
        if (b->x() < mView.sceneRect().bottomLeft().x())
        {
            b->setPos(mView.sceneRect().bottomLeft().x(), b->y());
            continue;
        }
        if (b->x() > mScene.sceneRect().topRight().x() - b->pixmap().rect().width())
        {
            b->setPos(mScene.sceneRect().topRight().x() - b->pixmap().rect().width(), b->y());
            continue;
        }
    }
}

void SpaceWars::setGameLevel(const QString &level)
{
    mCurrentLevel = level.toInt() - 1;
    mSpawnTimer.start (spawnTimeout[mCurrentLevel]);
}
