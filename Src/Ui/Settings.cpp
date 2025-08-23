#include "Settings.h"

Settings::Settings()
{
    languageSettingFile = new QFile;
}

Settings::~Settings()
{
    delete languageSettingFile;
}

void Settings::openJsonFile()
{

}
