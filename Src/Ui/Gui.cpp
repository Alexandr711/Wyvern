#include "Gui.h"

Gui::Gui()
{
    mainWindow = new MainWindow;

    menuBar = new QMenuBar;
    fileMenu = new FileMenu;

    mainToolBar = new MainToolBar;

    cadToolsToolBar = new CADToolsToolBar;
}

Gui::~Gui()
{
    delete cadToolsToolBar;

    delete mainToolBar;

    delete fileMenu;
    delete menuBar;

    delete mainWindow;
}

void Gui::setItems()
{
    mainWindow->setMenuBar(menuBar);

    menuBar->addMenu(fileMenu);

    mainWindow->addToolBar(mainToolBar);
    mainWindow->addToolBarBreak();
    mainWindow->addToolBar(cadToolsToolBar);

    mainToolBar->setItems();
    cadToolsToolBar->setItems();
}

void Gui::show()
{
    mainWindow->show();
}
