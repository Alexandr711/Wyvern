#include "MainToolBar.h"

MainToolBar::MainToolBar(QWidget* parent):
    QToolBar(parent)
{
    openButton = new QToolButton(this);
    createButton = new QToolButton(this);
    saveButton = new QToolButton(this);
    saveAllButton = new QToolButton(this);
    undoButton = new QToolButton(this);
    returnButton = new QToolButton(this);

    openButton->setObjectName("openButton");
    createButton->setObjectName("createButton");
    saveButton->setObjectName("saveButton");
    saveAllButton->setObjectName("saveAllButton");
    undoButton->setObjectName("undoButton");
    returnButton->setObjectName("returnButton");
}

MainToolBar::~MainToolBar()
{

}

void MainToolBar::setItems()
{
    addWidget(openButton);
    addWidget(createButton);
    addWidget(saveButton);
    addWidget(saveAllButton);
    addWidget(undoButton);
    addWidget(returnButton);
}

void MainToolBar::setOpenButtonToolTipTitle(QString title)
{
    openButton->setToolTip(title);
}

void MainToolBar::setCreateButtonToolTipTitle(QString title)
{
    createButton->setToolTip(title);
}

void MainToolBar::setSaveButtonToolTipTitle(QString title)
{
    saveButton->setToolTip(title);
}

void MainToolBar::setSaveAllButtonToolTipTitle(QString title)
{
    saveAllButton->setToolTip(title);
}

void MainToolBar::setUndoButtonToolTipTitle(QString title)
{
    undoButton->setToolTip(title);
}

void MainToolBar::setReturnButtonToolTipTitle(QString title)
{
    returnButton->setToolTip(title);
}

QToolButton* MainToolBar::getOpenButton()
{
    return openButton;
}

QToolButton *MainToolBar::getCreateButton()
{
    return createButton;
}

QToolButton *MainToolBar::getSaveButton()
{
    return saveButton;
}

QToolButton *MainToolBar::getSaveAllButton()
{
    return saveAllButton;
}

QToolButton *MainToolBar::getUndoButton()
{
    return undoButton;
}

QToolButton *MainToolBar::getReturnButton()
{
    return returnButton;
}



