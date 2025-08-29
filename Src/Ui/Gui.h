#ifndef GUI_H
#define GUI_H

#include <QMenuBar>

class Settings;

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
    void setTitleOnWidgets();
    void setColorTheme();
    void show();

public slots:
    void setRussianSlot();
    void setEnglishSlot();

    void setDarkThemeSlot();
    void setLightThemeSlot();
    void setSystemDarkThemeSlot();
    void setSystemLightThemeSlot();

private:
    Settings* settings;
    MainWindow* mainWindow;

    //MenuBar
    QMenuBar* menuBar;
    FileMenu* fileMenu;
    HelpMenu* helpMenu;

    MainToolBar* mainToolBar;

    CADToolsToolBar* cadToolsToolBar;
};

#endif // GUI_H
