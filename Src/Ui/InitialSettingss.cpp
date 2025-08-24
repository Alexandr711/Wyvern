#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

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

void InitialSettings::connections()
{
    connect(ui->selectColorThemeComboBox, SIGNAL(activated(int)), this, SLOT(setColorThemeSlot()));
    connect(ui->selectLanguageComboBox, SIGNAL(activated(int)), this, SLOT(setLanguageSlot()));
    connect(ui->cancelButton, SIGNAL(clicked(bool)), qApp, SLOT(quit()));
    connect(ui->okButton, SIGNAL(clicked(bool)), this, SLOT(okButtonSlot()));
}

void InitialSettings::setLanguageSlot()
{
    if(ui->selectLanguageComboBox->currentIndex() == ENGLISH)
    {
        languageString = "English.json";
        qDebug() << "Set ENGLISH language.";
    }
    else if(ui->selectLanguageComboBox->currentIndex() == RUSSIAN)
    {
        languageString = "Russian.json";
        qDebug() << "Set RUSSIAN language.";
    }
}

void InitialSettings::setColorThemeSlot()
{
    if(ui->selectColorThemeComboBox->currentIndex() == DARK_COLOR)
    {
        colorThemeString = "DarkColor.json";
    }
    else if(ui->selectColorThemeComboBox->currentIndex() == LIGHT_COLOR)
    {
        colorThemeString = "LightColor.json";
    }
}

void InitialSettings::okButtonSlot()
{
    QFile file("Config.json");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "Can't open config file.";
    }

    delete this;
}
