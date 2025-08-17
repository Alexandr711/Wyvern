#ifndef UI_H
#define UI_H

#include <QMenuBar>

#include "MainWindow/MainwWndow.h"
#include "MenuBar/FileMenu.h"
#include "ToolBars/MainToolBar.h"

class Gui
{
public:
    Gui();
    ~Gui();

    void setItems();

private:
    void setMenuBarItems();

private:
    MainWindow* mainWindow;

    //MenuBar
    QMenuBar* menuBar;
    FileMenu* fileMenu;

    //ToolBars
    MainToolBar* mainToolBar;

};

#endif // UI_H
