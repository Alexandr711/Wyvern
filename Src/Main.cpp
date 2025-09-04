#include <QApplication>

#include "Ui/Gui.h"
#include "Ui/InitialSettings.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    //app.setStyle("Fusion");

    InitialSettings gui;
    //gui.setSystemActionTitle();
    gui.startGui();
    gui.connections();

    return app.exec();
}
