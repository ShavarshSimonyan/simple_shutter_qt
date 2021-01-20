#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLabel>

class settingsPage: public QWidget
{
public:
    settingsPage (int width, int height, QWidget *parent = nullptr);

    QComboBox* getCombo ();
private:
    QLabel *mMenuTitle;
    QVBoxLayout *mMainLayout;
    QComboBox *mGameLevel;
    QPushButton *mCloseButton;

    const int mWidth;
    const int mHeight;
};

#endif // MENUPAGE_H
