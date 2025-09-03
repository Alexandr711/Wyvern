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

    inline void lineButtonSetTitle(QString title){lineButton->setToolTip(title);}
    inline void arcButtonSetTitle(QString title){arcButton->setToolTip(title);}
    inline void polylineButtonSetTitle(QString title){polylineButton->setToolTip(title);}
    inline void circleButtonSetTitle(QString title){circleButton->setToolTip(title);}
    inline void rectangleButtonSetTitle(QString title){rectangleButton->setToolTip(title);}

    void settingsMechanicalEngineringTabWidget();
    void settingsMicroElectronicTabWidget();
    void settingsElectricalEngineringTabWidget();
    void settingsArchitectureTabWidget();
private:
    QWidget* mainWidget;
    QHBoxLayout* mainLayout;
    QGridLayout* mainToolButtonLayout;

    QTabWidget* toolsTabWidget;

    QToolButton* lineButton;
    QToolButton* arcButton;
    QToolButton* polylineButton;
    QToolButton* circleButton;
    QToolButton* rectangleButton;

    QWidget* tabWidgetsItemWidget;

    QTabWidget* mechanicalEngineringTabWidget;
    QTabWidget* microElectronicTabWidget;
    QTabWidget* electricalEngineringTabWidget;
    QTabWidget* architectureTabWidget;

    PlanToolsWidget* planToolsWidget;

    struct MechanicalEngineringLabels;
    MechanicalEngineringLabels* mechanicalEngineringLabels;
};

#endif // CADTOOLSTOOLBAR_H
