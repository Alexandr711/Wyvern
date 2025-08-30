#ifndef SETTINGVALUES_H
#define SETTINGVALUES_H

#include <QString>

#ifdef WIN64
const inline QString RUSSIAN_JSON_FILE = ":/Languages/Src/Ui/Languages/Russian.json";
const inline QString ENGLISH_JSON_FILE = ":/Languages/Src/Ui/Languages/English.json";
#elif __APPLE__
const inline QString RUSSIAN_JSON_FILE = ":/Languages/Src/Ui/Languages/RussianMacOS.json";
const inline QString ENGLISH_JSON_FILE = ":/Languages/Src/Ui/Languages/EnglishMacOS.json";
#endif

#endif // SETTINGVALUES_H
