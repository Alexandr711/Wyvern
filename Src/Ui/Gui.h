#ifndef GUI_H
#define GUI_H

#include <QMenuBar>
#include <QObject>

class Settings;

class MainWindow;
class FileMenu;
class MainToolBar;
class HelpMenu;
class Settings;

//dialogs classes
class OpenDialog;
class CreateDialog;
class CADToolBar;
class CAD3DToolsWidget;

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

    void openOpenDialogSlot();
    void openCreateDialogSlot();

private:
    Settings* settings;
    MainWindow* mainWindow;

    //MenuBar
    QMenuBar* menuBar;
    FileMenu* fileMenu;
    HelpMenu* helpMenu;

    //Main Toolbar
    MainToolBar* mainToolBar;

    //Dialogs for main ToolBar
    OpenDialog* openDialog;
    CreateDialog* createDialog;

    //CADToolBar
    CADToolBar* cadToolBar;
    CAD3DToolsWidget* cad3DToolsWidget;
};

#endif // GUI_H
