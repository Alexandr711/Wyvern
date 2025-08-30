#include "Settings.h"

#include <QFile>
#include <QJsonDocument>
#include <QDebug>

Settings::Settings()
{

}

Settings::~Settings()
{

}

void Settings::readJsonFile(QString fileName)
{
    QFile jsonFile(fileName);
    if(!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Can't open json file: " << fileName << "!";
    }
    QString str;
    str = jsonFile.readAll();
    jsonFile.close();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
    jsonObject = jsonDoc.object();
}

void Settings::writeConfigJsonFile()
{
    QFile file("Config.json");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Can't open config file.";
    }

    QJsonDocument configureJsonDocument(jsonObject);
    QString configureJsonString = configureJsonDocument.toJson(QJsonDocument::Indented);

    QTextStream stream(&file);
    stream << configureJsonString;
    file.close();
}

void Settings::readQssFile(QString fileName)
{

}

QJsonObject Settings::getJsonObject()
{
    return jsonObject;
}
