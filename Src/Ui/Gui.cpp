#include <QFile>

#include "Gui.h"
#include "InitialSettings.h"
#include "MainWindow/MainWindow.h"
#include "MenuBar/FileMenu.h"
#include "MenuBar/HelpMenu.h"
#include "ToolBars/MainToolBar.h"
#include "ToolBars/CADToolsToolBar.h"

Gui::Gui()
{
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

void Gui::startGui()
{
    QFile configFile("Config.json");
    if(!configFile.open(QIODevice::ReadOnly))
    {
        InitialSettings* initialSettingsWindow = new InitialSettings;
        initialSettingsWindow->connections();
        initialSettingsWindow->show();
    }
}

void Gui::show()
{
    mainWindow->show();
}
