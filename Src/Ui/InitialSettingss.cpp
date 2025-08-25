#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "InitialSettings.h"
#include "ui_InitialSettings.h"
#include "Gui.h"

InitialSettings::InitialSettings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InitialSettings)
{
    gui = new Gui;
    ui->setupUi(this);
}

InitialSettings::~InitialSettings()
{
    delete gui;
    delete ui;
    qDebug() << "Delete initial settings window.";
}

void InitialSettings::mainWindowFunc()
{
    gui->setItems();
    gui->show();
}

void InitialSettings::startGui()
{
    QFile file("Config.json");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        this->show();
    }
    else
    {
        mainWindowFunc();
    }
}

void InitialSettings::connections()
{
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
        qDebug() << "Set DARK color theme.";
    }
    else if(ui->selectColorThemeComboBox->currentIndex() == LIGHT_COLOR)
    {
        colorThemeString = "LightColor.json";
        qDebug() << "Set LIGHT color theme.";
    }
}

void InitialSettings::okButtonSlot()
{
    QFile file("Config.json");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Can't open config file.";
    }

    setLanguageSlot();
    setColorThemeSlot();

    QJsonObject jsonRecordObject;
    jsonRecordObject.insert("Language", languageString);
    jsonRecordObject.insert("Theme", colorThemeString);

    QJsonDocument configureJsonDocument(jsonRecordObject);
    QString configureJsonString = configureJsonDocument.toJson(QJsonDocument::Indented);

    QTextStream stream(&file);
    stream << configureJsonString;
    file.close();

    this->hide();
    mainWindowFunc();
}
