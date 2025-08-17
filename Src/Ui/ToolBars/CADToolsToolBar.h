#ifndef CADTOOLSTOOLBAR_H
#define CADTOOLSTOOLBAR_H

#include <QToolBar>
#include <QTabWidget>

class CADToolsToolBar : public QToolBar
{
public:
    CADToolsToolBar(QWidget* parent = nullptr);
    ~CADToolsToolBar();

private:
    QTabWidget* toolsTabWidget;
};

#endif // CADTOOLSTOOLBAR_H
