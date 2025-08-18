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

void FileMenu::createMenuSetTitle(QString title)
{
    createMenu->setTitle(title);
}

void FileMenu::createFileActionSetTitle(QString title)
{
    createFileAction->setText(title);
}

void FileMenu::createProjectActionSetTitle(QString title)
{
    createProjectAction->setText(title);
}

void FileMenu::openMenuSetTitle(QString title)
{
    openMenu->setTitle(title);
}

void FileMenu::openFileActionSetTitle(QString title)
{
    openFileAction->setText(title);
}

void FileMenu::openProjectActionSetTitle(QString title)
{
    openProjectAction->setText(title);
}

QAction *FileMenu::getCreateFileAction()
{
    return createFileAction;
}

QAction *FileMenu::getCreateProjectAction()
{
    return createProjectAction;
}

QAction *FileMenu::getOpenFileAction()
{
    return openFileAction;
}

QAction *FileMenu::getOpenProjectAction()
{
    return openProjectAction;
}
