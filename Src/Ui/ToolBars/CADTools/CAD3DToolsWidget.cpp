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

    separatorOne = new QLabel;
    separatorTwo = new QLabel;

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
    mechanicalEngineringGridLayout = new QGridLayout;
    prismaButton = new QToolButton;

    separatorOne->setObjectName("separatorOne");

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
    sphereButton->setObjectName("sphereButton");
    parallelepipedButton->setObjectName("parallelepipedButton");
    cilinderButton->setObjectName("cilinderButton");
    coneButton->setObjectName("coneButton");
    pyramideButton->setObjectName("pyramideButton");
    torusButton->setObjectName("torusButton");
    prismaButton->setObjectName("prismaButton");
}

CAD3DToolsWidget::~CAD3DToolsWidget()
{
    delete prismaButton;
    delete mechanicalEngineringGridLayout;
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

    delete separatorTwo;
    delete separatorOne;

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
    mainHBoxLayout->setContentsMargins(9, 0, 0, 0);
    primitiveGridLayout->setContentsMargins(0, 0, 0, 0);
    primitiveGridLayout->setSpacing(0);

    primitiveGridLayout->addWidget(lineButton, 0, 0);
    primitiveGridLayout->addWidget(arcButton, 0, 1);
    primitiveGridLayout->addWidget(polylineButton, 0, 2);
    primitiveGridLayout->addWidget(circleButton, 1, 0);
    primitiveGridLayout->addWidget(rectangleButton, 1, 1);

    mainHBoxLayout->addWidget(separatorOne);

    mainHBoxLayout->addLayout(figure3DVBoxLayout);
    figure3DVBoxLayout->setContentsMargins(0, 0, 0, 0);
    figure3DVBoxLayout->setSpacing(0);

    figure3DVBoxLayout->addLayout(figure3DHBoxLayout);
    figure3DHBoxLayout->setContentsMargins(0, 0, 0, 0);
    figure3DHBoxLayout->setSpacing(0);

    //Add 3D figure buttons
    figure3DHBoxLayout->addWidget(sphereButton);
    figure3DHBoxLayout->addWidget(cilinderButton);
    figure3DHBoxLayout->addWidget(coneButton);
    figure3DHBoxLayout->addWidget(parallelepipedButton);
    figure3DHBoxLayout->addWidget(pyramideButton);
    figure3DHBoxLayout->addWidget(prismaButton);
    figure3DHBoxLayout->addWidget(torusButton);
    figure3DHBoxLayout->addStretch();

    figure3DVBoxLayout->addLayout(xyzHBoxLayout);

    //Add XYZ buttons
    xyzHBoxLayout->addWidget(xyButton);
    xyzHBoxLayout->addWidget(xyFButton);
    xyzHBoxLayout->addWidget(xzButton);
    xyzHBoxLayout->addWidget(xzFButton);
    xyzHBoxLayout->addWidget(yzButton);
    xyzHBoxLayout->addWidget(yzFButton);
    xyzHBoxLayout->addWidget(xyzButton);
    xyzHBoxLayout->setContentsMargins(0, 0, 0, 0);
    xyzHBoxLayout->setSpacing(0);
    xyzHBoxLayout->addStretch();

    mainHBoxLayout->addLayout(figure3DGridLayout);
    figure3DGridLayout->setContentsMargins(0, 0, 0, 0);
    figure3DGridLayout->setSpacing(0);

    figure3DGridLayout->addWidget(holeButton, 1, 0);
    figure3DGridLayout->addWidget(pullButton, 0 ,0);

    figure3DGridLayout->setContentsMargins(0, 0, 0, 0);
    figure3DGridLayout->setSpacing(0);

    mainHBoxLayout->addWidget(separatorTwo);
    mainHBoxLayout->addLayout(mechanicalEngineringGridLayout);
    mechanicalEngineringGridLayout->addWidget(chamferButton, 0, 0);
    mechanicalEngineringGridLayout->addWidget(grooveButton, 1, 0);

    mainHBoxLayout->addStretch(10);
}

