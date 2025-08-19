#ifndef GUI_H
#define GUI_H

#include <QMenuBar>

#include "MainWindow/MainWindow.h"
#include "MenuBar/FileMenu.h"

#include "ToolBars/MainToolBar.h"

class Gui
{
public:
    Gui();
    ~Gui();

    void setItems();
    void show();

private:
    MainWindow* mainWindow;

    //MenuBar
    QMenuBar* menuBar;
    FileMenu* fileMenu;

    MainToolBar* mainToolBar;
};

#endif // GUI_H
