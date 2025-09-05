#include "CADToolsToolBar.h"
//TabWidgets labels
struct CADToolsToolBar::MechanicalEngineringLabels
{
    QString planTabName;
    QString model3DTabName;
};



CADToolsToolBar::CADToolsToolBar(QWidget* parent):
    QToolBar(parent)
{
    mechanicalEngineringTabWidget = new QTabWidget;
    microElectronicTabWidget = new QTabWidget;
    electricalEngineringTabWidget = new QTabWidget;
    architectureTabWidget = new QTabWidget;

    mechanicalEngineringLabels = new MechanicalEngineringLabels;
}

CADToolsToolBar::~CADToolsToolBar()
{
    delete mechanicalEngineringLabels;

    delete architectureTabWidget;
    delete electricalEngineringTabWidget;
    delete microElectronicTabWidget;
    delete mechanicalEngineringTabWidget;
}

void CADToolsToolBar::setItems()
{

}

void CADToolsToolBar::settingsMechanicalEngineringTabWidget()
{
    mechanicalEngineringTabWidget->addTab(planToolsWidget, mechanicalEngineringLabels->planTabName);
    //mechanicalEngineringTabWidget->addTab();
}

