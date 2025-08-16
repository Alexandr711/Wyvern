#include "FileMenu.h"

FileMenu::FileMenu(QWidget* parent):
    QMenu(parent)
{
    createMenu = new QMenu(this);
    createFileAction = new QAction(this);
    createProjectAction = new QAction(this);

    openMenu = new QMenu(this);
    openFileAction = new QAction(this);
    openProjectAction = new QAction(this);
}

FileMenu::~FileMenu()
{

}

void FileMenu::setItems()
{
    addMenu(createMenu);
    createMenu->addAction(createFileAction);
    createMenu->addAction(createProjectAction);

    addMenu(openMenu);
    openMenu->addAction(openFileAction);
    openMenu->addAction(openProjectAction);


}
