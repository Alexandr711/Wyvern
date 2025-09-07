#include "CAD3DToolsWidget.h"

CAD3DToolsWidget::CAD3DToolsWidget(QWidget *parent)
    : QWidget{parent}
{
    mainHBoxLayout = new QHBoxLayout(this);

    primitiveGridLayout = new QGridLayout(this);
    lineButton = new QToolButton(this);
    arcButton = new QToolButton(this);
    polylineButton = new QToolButton(this);
    circleButton = new QToolButton(this);
    rectangleButton = new QToolButton(this);

    figure3DGridLayout = new QGridLayout(this);
    figure3DComboBox = new QComboBox(this);
    holeButton = new QToolButton(this);
    pullButton = new QToolButton(this);
    chamferButton = new QToolButton(this);
}

void CAD3DToolsWidget::setItems()
{
    setLayout(mainHBoxLayout);
    mainHBoxLayout->addLayout(primitiveGridLayout);
    primitiveGridLayout->addWidget(lineButton, 0, 0);
    primitiveGridLayout->addWidget(arcButton, 0, 1);
    primitiveGridLayout->addWidget(polylineButton, 0, 2);
    primitiveGridLayout->addWidget(circleButton, 1, 0);
    primitiveGridLayout->addWidget(rectangleButton, 1, 1);

    mainHBoxLayout->addWidget(separator);

    mainHBoxLayout->addLayout(figure3DGridLayout);
}
