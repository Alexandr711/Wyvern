#include "CADToolsToolBar.h"

CADToolsToolBar::CADToolsToolBar(QWidget* parent):
    QToolBar(parent)
{
    mainWidget = new QWidget(this);
    mainLayout = new QHBoxLayout(this);
    mainToolButtonLayout = new QGridLayout(this);

    lineButton = new QToolButton(this);
    arcButton = new QToolButton(this);
    polyLineButton = new QToolButton(this);
    circleButton = new QToolButton(this);
    rectangleButton = new QToolButton(this);
}

CADToolsToolBar::~CADToolsToolBar()
{}

void CADToolsToolBar::setItems()
{
    addWidget(mainWidget);

    mainWidget->setLayout(mainLayout);
    mainLayout->addLayout(mainToolButtonLayout);

    mainToolButtonLayout->addWidget(lineButton, 0, 0);
    mainToolButtonLayout->addWidget(arcButton, 0, 1);
    mainToolButtonLayout->addWidget(polyLineButton, 0, 2);
    mainToolButtonLayout->addWidget(circleButton, 1, 0);
    mainToolButtonLayout->addWidget(rectangleButton, 1, 1);
}
