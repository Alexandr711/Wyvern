#include "Gui.h"

Gui::Gui()
{
    mainWindow = new MainWindow();

    menuBar = new QMenuBar(mainWindow);
    fileMenu = new FileMenu(menuBar);

    mainToolBar = new MainToolBar(mainWindow);

    cadToolsToolBar = new CADToolsToolBar(mainWindow);
}

Gui::~Gui()
{
    delete mainWindow;
}

void Gui::setItems()
{
    mainWindow->setMenuBar(menuBar);

    menuBar->addMenu(fileMenu);

    mainWindow->addToolBar(mainToolBar);
    mainWindow->addToolBar(cadToolsToolBar);
}

void Gui::show()
{
    mainWindow->show();
}
