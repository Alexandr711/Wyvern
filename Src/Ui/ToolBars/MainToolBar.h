#ifndef MAINTOOLBAR_H
#define MAINTOOLBAR_H

#include <QToolBar>
#include <QToolBar>

class MainToolBar : public QToolBar
{
public:
    MainToolBar();

private:

    QToolBar* openButton;
    QToolBar* createButton;
};

#endif // MAINTOOLBAR_H
