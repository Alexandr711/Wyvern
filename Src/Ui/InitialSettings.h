#ifndef INITIALSETTINGS_H
#define INITIALSETTINGS_H

#include <QWidget>

class Gui;

//Languages constants
const unsigned int ENGLISH = 0;
const unsigned int RUSSIAN = 1;

//Color theme constants
const unsigned int DARK_COLOR = 0;
const unsigned int LIGHT_COLOR = 1;


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

public slots:
    void setLanguageSlot();
    void setColorThemeSlot();
    void okButtonSlot();

private:
    Ui::InitialSettings *ui;
    Gui* gui;

    QString languageString;
    QString colorThemeString;
};

#endif // INITIALSETTINGS_H
