#ifndef GUI_H
#define GUI_H

#include <QMenuBar>

class MainWindow;
class FileMenu;
class MainToolBar;
class CADToolsToolBar;
class HelpMenu;
class Settings;

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
    HelpMenu* helpMenu;

    MainToolBar* mainToolBar;

    CADToolsToolBar* cadToolsToolBar;
};

#endif // GUI_H
