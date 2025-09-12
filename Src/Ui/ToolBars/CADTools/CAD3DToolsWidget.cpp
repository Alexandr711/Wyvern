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
    grooveButton = new QToolButton;

    xyzHBoxLayout = new QHBoxLayout;
    xyButton = new QToolButton;
    xzButton = new QToolButton;
    yzButton = new QToolButton;
    xyzButton = new QToolButton;

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
}

CAD3DToolsWidget::~CAD3DToolsWidget()
{
    delete xyzButton;
    delete yzButton;
    delete xzButton;
    delete xyButton;
    delete xyzHBoxLayout;

    delete grooveButton;
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
    primitiveGridLayout->setSpacing(0);

    primitiveGridLayout->addWidget(lineButton, 0, 0);
    primitiveGridLayout->addWidget(arcButton, 0, 1);
    primitiveGridLayout->addWidget(polylineButton, 0, 2);
    primitiveGridLayout->addWidget(circleButton, 1, 0);
    primitiveGridLayout->addWidget(rectangleButton, 1, 1);

    mainHBoxLayout->addWidget(separator);

    mainHBoxLayout->addLayout(figure3DVBoxLayout);
    figure3DVBoxLayout->addWidget(figure3DComboBox);
    figure3DVBoxLayout->addLayout(xyzHBoxLayout);
    xyzHBoxLayout->addWidget(xyButton);
    xyzHBoxLayout->addWidget(xzButton);
    xyzHBoxLayout->addWidget(yzButton);
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

    figure3DComboBox->addItem(QIcon(sphereIcon), sphereString);
    figure3DComboBox->addItem(QIcon(cilindrIcon), cilindrString);
    figure3DComboBox->addItem(QIcon(parallelepipedIcon), parallelepipedString);
    figure3DComboBox->addItem(QIcon(coneIcon), coneString);
    figure3DComboBox->addItem(QIcon(pyramidIcon), pyramidString);
    figure3DComboBox->addItem(QIcon(torusIcon), torusString);
    figure3DComboBox->setIconSize(QSize(20, 20));
}

void CAD3DToolsWidget::setItemsText()
{
    figure3DComboBox->setItemText(0, sphereString);
    figure3DComboBox->setItemText(1, cilindrString);
    figure3DComboBox->setItemText(2, parallelepipedString);
    figure3DComboBox->setItemText(3, coneString);
    figure3DComboBox->setItemText(4, pyramidString);
    figure3DComboBox->setItemText(5, torusString);
}

void CAD3DToolsWidget::setItemsIcons()
{
    figure3DComboBox->setItemIcon(0, QIcon(sphereIcon));
    figure3DComboBox->setItemIcon(1, QIcon(cilindrIcon));
    figure3DComboBox->setItemIcon(2, QIcon(parallelepipedIcon));
    figure3DComboBox->setItemIcon(3, QIcon(coneIcon));
    figure3DComboBox->setItemIcon(4, QIcon(pyramidIcon));
    figure3DComboBox->setItemIcon(5, QIcon(torusIcon));
}

