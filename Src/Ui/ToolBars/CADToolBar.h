#ifndef CADTOOLBAR_H
#define CADTOOLBAR_H

#include <QToolBar>
#include <QGridLayout>
#include <QToolButton>
#include <QComboBox>
#include <QTabWidget>

class CADToolBar : public QToolBar
{
public:
    explicit CADToolBar(QWidget* parent = nullptr);
    ~CADToolBar();

    void setItems();

    void addPlanTab(QWidget*);
    void addCad3DToolsTab(QWidget*);
    void setTabsText();

    inline void setPlanString(QString str){planString = str;}
    inline void setCad3DToolsString(QString str){cad3DToolsString = str;}

private:
    QTabWidget* toolTabWidget;

    //Labels of tabs
    QString planString;
    QString cad3DToolsString;
};

#endif // CADTOOLBAR_H
