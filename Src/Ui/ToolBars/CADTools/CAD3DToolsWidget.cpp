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
    figure3DVBoxLayout = new QVBoxLayout;

    figure3DComboBox = new QComboBox;
    holeButton = new QToolButton;
    pullButton = new QToolButton;
    chamferButton = new QToolButton;

    lineButton->setObjectName("lineButton");
    arcButton->setObjectName("arcButton");
}

CAD3DToolsWidget::~CAD3DToolsWidget()
{
    delete chamferButton;
    delete pullButton;
    delete holeButton;
    delete figure3DComboBox;

    delete figure3DVBoxLayout;
    delete figure3DGridLayout;

    delete separator;

    delete rectangleButton;
    delete circleButton;
    delete polylineButton;
    delete arcButton;
    delete lineButton;
    delete primitiveGridLayout;
    delete mainHBoxLayout;
}



void CAD3DToolsWidget::setItems()
{
    setLayout(mainHBoxLayout);
    mainHBoxLayout->addLayout(primitiveGridLayout, Qt::LeftToRight);
    mainHBoxLayout->setContentsMargins(8, 2, 0, 0);
    primitiveGridLayout->setContentsMargins(0, 0, 0, 0);
    primitiveGridLayout->setSpacing(2);

    primitiveGridLayout->addWidget(lineButton, 0, 0);
    primitiveGridLayout->addWidget(arcButton, 0, 1);
    primitiveGridLayout->addWidget(polylineButton, 0, 2);
    primitiveGridLayout->addWidget(circleButton, 1, 0);
    primitiveGridLayout->addWidget(rectangleButton, 1, 1);

    lineButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    arcButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    polylineButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    circleButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
    rectangleButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);


    mainHBoxLayout->addWidget(separator);

    mainHBoxLayout->addLayout(figure3DVBoxLayout);
    figure3DVBoxLayout->addWidget(figure3DComboBox);
    figure3DVBoxLayout->addStretch();

    mainHBoxLayout->addLayout(figure3DGridLayout);
    figure3DGridLayout->setContentsMargins(0, 0, 0, 0);
    figure3DGridLayout->setSpacing(0);

    figure3DGridLayout->addWidget(holeButton, 0, 0);
    figure3DGridLayout->addWidget(pullButton, 1 ,0);
    figure3DGridLayout->addWidget(chamferButton, 2, 0);
    mainHBoxLayout->addStretch();
}
