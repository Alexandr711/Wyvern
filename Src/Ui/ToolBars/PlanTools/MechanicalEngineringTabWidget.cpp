#include "MechanicalEngineringTabWidget.h"
#include "ui_MechanicalEngineringTabWidget.h"

MechanicalEngineringTabWidget::MechanicalEngineringTabWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MechanicalEngineringTabWidget)
{
    ui->setupUi(this);
}

MechanicalEngineringTabWidget::~MechanicalEngineringTabWidget()
{
    delete ui;
}
