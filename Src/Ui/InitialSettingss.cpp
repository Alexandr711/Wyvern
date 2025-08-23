#include "InitialSettings.h"
#include "ui_InitialSettings.h"

InitialSettings::InitialSettings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InitialSettings)
{
    ui->setupUi(this);
}

InitialSettings::~InitialSettings()
{
    delete ui;
}

void InitialSettings::setLanguageSlot()
{

}

void InitialSettings::setColorThemeSlot()
{

}
