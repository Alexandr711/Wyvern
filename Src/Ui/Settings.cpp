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
    if(!jsonFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Can't open json file." << fileName << "!";
    }
    QString str;
    str = jsonFile.readAll();
    jsonFile.close();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(str.toUtf8());
    jsonObject = jsonDoc.object();
}

QJsonObject Settings::getJsonObject()
{
    return jsonObject;
}
