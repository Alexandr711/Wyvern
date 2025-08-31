#ifndef SETTINGVALUES_H
#define SETTINGVALUES_H

#include <QString>

#ifdef WIN64
const inline QString RUSSIAN_JSON_FILE = ":/Languages/Src/Ui/Languages/Russian.json";
const inline QString ENGLISH_JSON_FILE = ":/Languages/Src/Ui/Languages/English.json";

const inline QString SYSTEM_DARK_COLOR_STRING = ":/ColorThemes/Src/Ui/Styles/WindowsDarkStyle/WindowsDarkTheme.json";
const inline QString SYSTEM_LIGHT_COLOR_STRING = ":/ColorThemes/Src/Ui/Styles/WIndowsLightStyle/WindowsLightTheme.json";
#elif __APPLE__
const inline QString RUSSIAN_JSON_FILE = ":/Languages/Src/Ui/Languages/RussianMacOS.json";
const inline QString ENGLISH_JSON_FILE = ":/Languages/Src/Ui/Languages/EnglishMacOS.json";

const inline QString SYSTEM_DARK_COLOR_STRING = ":/ColorThemes/Src/Ui/Styles/MacOSDarkStyle/MacOSDarkStyle.json";
const inline QString SYSTEM_LIGHT_COLOR_STRING = ":/ColorThemes/Src/Ui/Styles/MacOSLightStyle/MacOSLightStyle.json";
#endif


#endif // SETTINGVALUES_H
