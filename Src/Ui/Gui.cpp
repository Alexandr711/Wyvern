#include "Gui.h"

Gui::Gui()
{
    mainWindow = new MainWindow();

    menuBar = new QMenuBar(mainWindow);
    fileMenu = new FileMenu(menuBar);

    mainToolBar = new MainToolBar(mainWindow);
}

Gui::~Gui()
{
    delete mainWindow;
}

void Gui::show()
{
    mainWindow->show();
}
