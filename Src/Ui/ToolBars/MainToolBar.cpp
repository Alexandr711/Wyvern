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
