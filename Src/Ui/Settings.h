#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QJsonObject>

class FileMenu;
class MainToolBar;
class CADToolsToolBar;

class Settings
{
public:
    Settings();
    ~Settings();

    void readJsonFile(QString);
    void writeJsonFile(QString);
    void readQssFile(QString);

    //Getters
    QJsonObject getJsonObject();

    //Setters
    inline void setJsonObject(QJsonObject val){jsonObject = val;}

private:
    QString languageString;
    QString configString;
    QJsonObject jsonObject;
};

#endif // SETTINGS_H
