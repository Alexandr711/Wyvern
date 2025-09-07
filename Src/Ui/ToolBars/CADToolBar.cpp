#include "CADToolBar.h"

CADToolBar::CADToolBar(QWidget* parent): QToolBar(parent)
{
    toolTabWidget = new QTabWidget;

    toolTabWidget->setObjectName("toolTabWidget");
}

CADToolBar::~CADToolBar()
{
    delete toolTabWidget;
}

void CADToolBar::setItems()
{
    addWidget(toolTabWidget);
    toolTabWidget->contentsMargins();
}

void CADToolBar::addPlanTab(QWidget* planTab)
{
    toolTabWidget->addTab(planTab, planString);
}

void CADToolBar::addCad3DToolsTab(QWidget* cad3dToolsTab)
{
    toolTabWidget->addTab(cad3dToolsTab, cad3DToolsString);
}

void CADToolBar::setTabsText()
{
    toolTabWidget->setTabText(0, planString);
    toolTabWidget->setTabText(1, cad3DToolsString);
}
