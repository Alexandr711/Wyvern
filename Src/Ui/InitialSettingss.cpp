#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "InitialSettings.h"
#include "ui_InitialSettings.h"
#include "Gui.h"
#include "SettingValues.h"


InitialSettings::InitialSettings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::InitialSettings)
{
    gui = new Gui;
    ui->setupUi(this);

    englishFlag = false;
    russianFlag = false;

    darkThemeFlag = false;
    lightThemeFlag = false;
    systemDarkThemeFlag = false;
    systemLightThemeFlag = false;
}

InitialSettings::~InitialSettings()
{
    delete gui;
    delete ui;
}

void InitialSettings::mainWindowFunc()
{
    gui->connections();
    gui->setColorTheme();
    gui->setTitleOnWidgets();
    gui->setItems();
    gui->setFlags();
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
        languageString = ENGLISH_JSON_FILE;
        englishFlag = true;
    }
    else if(ui->selectLanguageComboBox->currentIndex() == RUSSIAN)
    {
        languageString = RUSSIAN_JSON_FILE;
        russianFlag = true;
    }
}

void InitialSettings::setColorThemeSlot()
{
    if(ui->selectColorThemeComboBox->currentIndex() == DARK_COLOR)
    {
        colorThemeString = ":/ColorThemes/Src/Ui/Styles/DarkStyle/DarkStyle.json";
        darkThemeFlag = true;
    }
    else if(ui->selectColorThemeComboBox->currentIndex() == LIGHT_COLOR)
    {
        colorThemeString = ":/ColorThemes/Src/Ui/Styles/LightStyle/LightStyle.json";
        lightThemeFlag = true;
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
    jsonRecordObject.insert("English flag", englishFlag);
    jsonRecordObject.insert("Russian flag", russianFlag);
    jsonRecordObject.insert("Dark flag", darkThemeFlag);
    jsonRecordObject.insert("Light flag", lightThemeFlag);


    QJsonDocument configureJsonDocument(jsonRecordObject);
    QString configureJsonString = configureJsonDocument.toJson(QJsonDocument::Indented);

    QTextStream stream(&file);
    stream << configureJsonString;
    file.close();

    this->hide();
    mainWindowFunc();
}
