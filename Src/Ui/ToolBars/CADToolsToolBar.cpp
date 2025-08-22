#include "CADToolsToolBar.h"

CADToolsToolBar::CADToolsToolBar(QWidget* parent):
    QToolBar(parent)
{
    mainWidget = new QWidget;
    mainLayout = new QHBoxLayout;
    mainToolButtonLayout = new QGridLayout;

    lineButton = new QToolButton;
    arcButton = new QToolButton;
    polylineButton = new QToolButton;
    circleButton = new QToolButton;
    rectangleButton = new QToolButton;
}

CADToolsToolBar::~CADToolsToolBar()
{
    delete rectangleButton;
    delete circleButton;
    delete polylineButton;
    delete arcButton;
    delete lineButton;

    delete mainToolButtonLayout;
    delete mainLayout;
    delete mainWidget;
}

void CADToolsToolBar::setItems()
{
    addWidget(mainWidget);

    mainWidget->setLayout(mainLayout);
    mainLayout->addLayout(mainToolButtonLayout);

    mainToolButtonLayout->addWidget(lineButton, 0, 0);
    mainToolButtonLayout->addWidget(arcButton, 0, 1);
    mainToolButtonLayout->addWidget(polylineButton, 0, 2);
    mainToolButtonLayout->addWidget(circleButton, 1, 0);
    mainToolButtonLayout->addWidget(rectangleButton, 1, 1);

    mainToolButtonLayout->setSpacing(0);
    mainToolButtonLayout->setContentsMargins(1, 1, 1, 1);
    mainLayout->setContentsMargins(1, 1, 1, 1);
}
