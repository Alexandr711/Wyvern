#include <QApplication>

#include "Ui/Gui.h"
#include "Ui/InitialSettings.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    //app.setStyle("windowsvista");

    InitialSettings gui;
    //gui.setSystemActionTitle();
    gui.startGui();
    gui.connections();

    return app.exec();
}
