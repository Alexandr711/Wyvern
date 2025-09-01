#ifndef GUI_H
#define GUI_H

#include <QMenuBar>
#include <QObject>

class Settings;

class MainWindow;
class FileMenu;
class MainToolBar;
class CADToolsToolBar;
class HelpMenu;
class Settings;

class Gui: QObject
{
    Q_OBJECT
public:
    Gui();
    ~Gui();

    void setItems();
    void setTitleOnWidgets();
    void setColorTheme();
    void setFlags();
    void connections();
    void show();

public slots:
    void setRussianSlot();
    void setEnglishSlot();

    void setDarkThemeSlot();
    void setLightThemeSlot();

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
