#include <QFile>
#include <QJsonObject>
#include <QFileInfo>

#include "Gui.h"
#include "InitialSettings.h"
#include "MainWindow/MainWindow.h"
#include "MenuBar/FileMenu.h"
#include "MenuBar/HelpMenu.h"
#include "ToolBars/MainToolBar.h"
#include "ToolBars/CADToolsToolBar.h"
#include "Settings.h"

Gui::Gui()
{
    settings = new Settings;
    mainWindow = new MainWindow;

    menuBar = new QMenuBar;
    fileMenu = new FileMenu;
    helpMenu = new HelpMenu;

    mainToolBar = new MainToolBar;

    cadToolsToolBar = new CADToolsToolBar;
}

Gui::~Gui()
{
    delete cadToolsToolBar;

    delete mainToolBar;

    delete helpMenu;
    delete fileMenu;
    delete menuBar;

    delete mainWindow;
    delete settings;
}

void Gui::setItems()
{
    mainWindow->setMenuBar(menuBar);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(helpMenu);
    fileMenu->setItems();
    helpMenu->setItems();

    mainWindow->addToolBar(mainToolBar);
    mainWindow->addToolBarBreak();
    mainWindow->addToolBar(cadToolsToolBar);

    mainToolBar->setItems();
    cadToolsToolBar->setItems();
}

void Gui::setTitleOnWidgets()
{
    settings->readJsonFile("Config.json");

    //Open config.json file
    QJsonObject tempJsonObject = settings->getJsonObject();
    QString languageFileName = tempJsonObject["Language"].toString();


    //Open json file whith language settings
    settings->readJsonFile(languageFileName);
    tempJsonObject = settings->getJsonObject();

    QFileInfo fileInfo(languageFileName);
    if(!fileInfo.exists())
    {
        qDebug() << "Файл не найден вресурсах!";
    }

    fileMenu->setTitle(tempJsonObject["File"].toString());
    fileMenu->createMenuSetTitle(tempJsonObject["Create"].toString());
    fileMenu->createFileActionSetTitle(tempJsonObject["Create file"].toString());
    fileMenu->createProjectActionSetTitle(tempJsonObject["Create project"].toString());
    fileMenu->openMenuSetTitle(tempJsonObject["Open"].toString());
    fileMenu->openFileActionSetTitle(tempJsonObject["Open file"].toString());
    fileMenu->openProjectActionSetTitle(tempJsonObject["Open project"].toString());


    mainToolBar->setOpenButtonToolTipTitle(tempJsonObject["Open tooltip"].toString());
    mainToolBar->setCreateButtonToolTipTitle(tempJsonObject["Create tooltip"].toString());
    mainToolBar->setSaveButtonToolTipTitle(tempJsonObject["Save tooltip"].toString());
    mainToolBar->setSaveAllButtonToolTipTitle(tempJsonObject["Save all tooltip"].toString());
    mainToolBar->setUndoButtonToolTipTitle(tempJsonObject["Undo tooltip"].toString());
    mainToolBar->setReturnButtonToolTipTitle(tempJsonObject["Return tooltip"].toString());
}


void Gui::show()
{
    mainWindow->show();
}
