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

    holeButton = new QToolButton;
    pullButton = new QToolButton;
    chamferButton = new QToolButton;
    grooveButton = new QToolButton;

    xyzHBoxLayout = new QHBoxLayout;
    xyButton = new QToolButton;
    xzButton = new QToolButton;
    yzButton = new QToolButton;
    xyzButton = new QToolButton;
    xyFButton = new QToolButton;
    xzFButton = new QToolButton;
    yzFButton = new QToolButton;

    figure3DHBoxLayout = new QHBoxLayout;
    sphereButton = new QToolButton;
    parallelepipedButton = new QToolButton;
    cilinderButton = new QToolButton;
    coneButton = new QToolButton;
    pyramideButton = new QToolButton;
    torusButton = new QToolButton;

    lineButton->setObjectName("lineButton");
    arcButton->setObjectName("arcButton");
    polylineButton->setObjectName("polyLineButton");
    circleButton->setObjectName("circleButton");
    rectangleButton->setObjectName("rectangleButton");
    holeButton->setObjectName("holeButton");
    pullButton->setObjectName("pullButton");
    chamferButton->setObjectName("chamferButton");
    grooveButton->setObjectName("grooveButton");
    xyButton->setObjectName("xyButton");
    xzButton->setObjectName("xzButton");
    yzButton->setObjectName("yzButton");
    xyzButton->setObjectName("xyzButton");
    xyFButton->setObjectName("xyFButton");
    xzFButton->setObjectName("xzFButton");
    yzFButton->setObjectName("yzFButton");
}

CAD3DToolsWidget::~CAD3DToolsWidget()
{
    delete torusButton;
    delete pyramideButton;
    delete coneButton;
    delete cilinderButton;
    delete parallelepipedButton;
    delete sphereButton;
    delete figure3DHBoxLayout;

    delete yzFButton;
    delete xzFButton;
    delete xyFButton;

    delete xyzButton;
    delete yzButton;
    delete xzButton;
    delete xyButton;
    delete xyzHBoxLayout;

    delete grooveButton;
    delete chamferButton;
    delete pullButton;
    delete holeButton;

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
    primitiveGridLayout->setSpacing(0);

    primitiveGridLayout->addWidget(lineButton, 0, 0);
    primitiveGridLayout->addWidget(arcButton, 0, 1);
    primitiveGridLayout->addWidget(polylineButton, 0, 2);
    primitiveGridLayout->addWidget(circleButton, 1, 0);
    primitiveGridLayout->addWidget(rectangleButton, 1, 1);

    mainHBoxLayout->addWidget(separator);

    mainHBoxLayout->addLayout(figure3DVBoxLayout);

    figure3DVBoxLayout->addLayout(xyzHBoxLayout);
    xyzHBoxLayout->addWidget(xyButton);
    xyzHBoxLayout->addWidget(xyFButton);
    xyzHBoxLayout->addWidget(xzButton);
    xyzHBoxLayout->addWidget(xzFButton);
    xyzHBoxLayout->addWidget(yzButton);
    xyzHBoxLayout->addWidget(yzFButton);
    xyzHBoxLayout->addWidget(xyzButton);
    figure3DVBoxLayout->setContentsMargins(0, 0, 0, 0);
    xyzHBoxLayout->setContentsMargins(0, 0, 0, 0);

    mainHBoxLayout->addLayout(figure3DGridLayout);
    figure3DGridLayout->setContentsMargins(0, 0, 0, 0);
    figure3DGridLayout->setSpacing(0);

    figure3DGridLayout->addWidget(holeButton, 0, 0);
    figure3DGridLayout->addWidget(pullButton, 1 ,0);
    figure3DGridLayout->addWidget(chamferButton, 0, 1);
    figure3DGridLayout->addWidget(grooveButton, 1, 1);
    mainHBoxLayout->addStretch();
}

