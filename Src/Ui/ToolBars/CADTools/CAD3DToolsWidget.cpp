#include "CAD3DToolsWidget.h"

CAD3DToolsWidget::CAD3DToolsWidget(QWidget *parent)
    : QWidget{parent}
{
    mainHBoxLayout = new QHBoxLayout();

    primitiveGridLayout = new QGridLayout();
    lineButton = new QToolButton;
    arcButton = new QToolButton;
    polylineButton = new QToolButton;
    circleButton = new QToolButton;
    rectangleButton = new QToolButton;

    separator = new QLabel;

    figure3DGridLayout = new QGridLayout;
    figure3DComboBox = new QComboBox;
    holeButton = new QToolButton;
    pullButton = new QToolButton;
    chamferButton = new QToolButton;
}

CAD3DToolsWidget::~CAD3DToolsWidget()
{
    delete chamferButton;
    delete pullButton;
    delete holeButton;
    delete figure3DComboBox;
    delete figure3DGridLayout;

}



void CAD3DToolsWidget::setItems()
{
    setLayout(mainHBoxLayout);
    mainHBoxLayout->addLayout(primitiveGridLayout, Qt::LeftToRight);
    mainHBoxLayout->setStretch(0, 0);
    primitiveGridLayout->setSpacing(0);
    primitiveGridLayout->addWidget(lineButton, 0, 0);
    primitiveGridLayout->addWidget(arcButton, 0, 1);
    primitiveGridLayout->addWidget(polylineButton, 0, 2);
    primitiveGridLayout->addWidget(circleButton, 1, 0);
    primitiveGridLayout->addWidget(rectangleButton, 1, 1);

    mainHBoxLayout->addWidget(separator);

    mainHBoxLayout->addLayout(figure3DGridLayout);
    figure3DGridLayout->setSpacing(0);
    figure3DGridLayout->addWidget(figure3DComboBox, 0, 0);
    figure3DGridLayout->addWidget(holeButton, 0, 1);
    figure3DGridLayout->addWidget(pullButton, 1 ,1);
    figure3DGridLayout->addWidget(chamferButton, 2, 1);
}
