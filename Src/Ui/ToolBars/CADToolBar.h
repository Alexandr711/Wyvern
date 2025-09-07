#ifndef CADTOOLBAR_H
#define CADTOOLBAR_H

#include <QToolBar>
#include <QGridLayout>
#include <QToolButton>
#include <QComboBox>
#include <QTabWidget>

class MainToolsToolBar : public QToolBar
{
public:
    MainToolsToolBar(QWidget* parent = nullptr);

private:
    QTabWidget* toolTabWidget;
};

#endif // CADTOOLBAR_H
