#include "Settings.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

Settings::Settings()
{

}

Settings::~Settings()
{

}

void Settings::openJsonFile(QString fileName)
{
    QFile jsonFile(fileName);
    if(!jsonFile.open(QIODevice::ReadOnly))
    {
        qDebug() << "Can't open " << fileName << "!";
    }
}
