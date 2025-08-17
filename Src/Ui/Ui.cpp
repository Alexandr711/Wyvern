#include "Ui.h"

Gui::Gui()
{
    mainWindow = new MainWindow(this);

    menuBar = new QMenuBar(this);
    fileMenu = new FileMenu(this);

    mainToolBar = new MainToolBar(this);
}

Gui::~Gui(){}

void Gui::setItems()
{
    mainWindow->setMenuBar(menuBar);
    setMenuBarItems();
    fileMenu->setItems();

    mainWindow->addToolBar(mainToolBar);


}

void Gui::setMenuBarItems()
{
    menuBar->addMenu(fileMenu);
}

