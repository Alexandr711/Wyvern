#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>

class FileMenu;
class MainToolBar;
class CADToolsToolBar;

class Settings
{
public:
    Settings();
    ~Settings();

    void openJsonFile(QString);

private:
    QString languageString;
    QString configString;
};

#endif // SETTINGS_H
