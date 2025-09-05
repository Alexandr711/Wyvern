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

    void settingsMechanicalEngineringTabWidget();
    void settingsMicroElectronicTabWidget();
    void settingsElectricalEngineringTabWidget();
    void settingsArchitectureTabWidget();
private:
    QTabWidget* mechanicalEngineringTabWidget;
    QTabWidget* microElectronicTabWidget;
    QTabWidget* electricalEngineringTabWidget;
    QTabWidget* architectureTabWidget;

    PlanToolsWidget* planToolsWidget;

    struct MechanicalEngineringLabels;
    MechanicalEngineringLabels* mechanicalEngineringLabels;
};

#endif // CADTOOLSTOOLBAR_H
