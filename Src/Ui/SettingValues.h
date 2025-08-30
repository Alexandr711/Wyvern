#ifndef SETTINGVALUES_H
#define SETTINGVALUES_H

#include <QString>


#ifdef WIN64
QString RUSSIAN_JSON_FILE = ":/Languages/Src/Ui/Languages/Russian.json";
QString ENGLISH_JSON_FILE = ":/Languages/Src/Ui/Languages/English.json";
#elif __APPLE__
QString RUSSIAN_JSON_FILE = ":/Languages/Src/Ui/Languages/Russian.json";
QString ENGLISH_JSON_FILE = ":/Languages/Src/Ui/Languages/English.json";
#endif

#endif // SETTINGVALUES_H
