#include <QApplication>

#include "Ui/Gui.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    Gui gui;
    gui.startGui();
    gui.setItems();
    gui.show();

    return app.exec();
}
