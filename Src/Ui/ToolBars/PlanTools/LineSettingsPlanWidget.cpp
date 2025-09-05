#include "LineSettingsPlanWidget.h"
#include "ui_LineSettingsPlanWidget.h"

LineSettingsPlanWidget::LineSettingsPlanWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LineSettingsPlanWidget)
{
    ui->setupUi(this);
}

LineSettingsPlanWidget::~LineSettingsPlanWidget()
{
    delete ui;
}
