#include "MechanicalEngineringWidget.h"
#include "ui_MechanicalEngineringWidget.h"

MechanicalEngineringWidget::MechanicalEngineringWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MechanicalEngineringWidget)
{
    ui->setupUi(this);
}

MechanicalEngineringWidget::~MechanicalEngineringWidget()
{
    delete ui;
}
