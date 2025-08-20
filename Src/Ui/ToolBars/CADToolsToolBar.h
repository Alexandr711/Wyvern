#ifndef CADTOOLSTOOLBAR_H
#define CADTOOLSTOOLBAR_H

#include <QToolBar>
#include <QTabWidget>
#include <QGridLayout>
#include <QHBoxLayout>

#include "PlanToolsWidget.h"

class CADToolsToolBar : public QToolBar
{
public:
    CADToolsToolBar(QWidget* parent = nullptr);
    ~CADToolsToolBar();

    void setItems();

private:
    QWidget* mainWidget;
    QHBoxLayout* mainLayout;
    QGridLayout* mainToolButtonLayout;

    QTabWidget* toolsTabWidget;

    QToolButton* lineButton;
    QToolButton* arcButton;
    QToolButton* polyLineButton;
    QToolButton* circleButton;
    QToolButton* rectangleButton;

    PlanToolsWidget* planToolsWidget;
};

#endif // CADTOOLSTOOLBAR_H
