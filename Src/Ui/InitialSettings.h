#ifndef INITIALSETTINGS_H
#define INITIALSETTINGS_H

#include <QAction>
#include <QWidget>

class Gui;

//Languages constants
const unsigned int ENGLISH = 0;
const unsigned int RUSSIAN = 1;

//Color theme constants
const unsigned int DARK_COLOR = 0;
const unsigned int LIGHT_COLOR = 1;
const unsigned int SYSTEM_DARK_COLOR = 2;
const unsigned int SYSTEM_LIGHT_COLOR = 3;



namespace Ui {
class InitialSettings;
}

class InitialSettings : public QWidget
{
    Q_OBJECT

public:
    explicit InitialSettings(QWidget *parent = nullptr);
    ~InitialSettings();

    void connections();
    void mainWindowFunc();
    void startGui();
    void setSystemActionTitle();

public slots:
    void setLanguageSlot();
    void setColorThemeSlot();
    void okButtonSlot();

private:
    Ui::InitialSettings *ui;
    Gui* gui;

    QString languageString;
    QString colorThemeString;

    bool englishFlag;
    bool russianFlag;

    bool darkThemeFlag;
    bool lightThemeFlag;
    bool systemDarkThemeFlag;
    bool systemLightThemeFlag;
};

#endif // INITIALSETTINGS_H
