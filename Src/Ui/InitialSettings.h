#ifndef INITIALSETTINGS_H
#define INITIALSETTINGS_H

#include <QWidget>

namespace Ui {
class InitialSettings;
}

class InitialSettings : public QWidget
{
    Q_OBJECT

public:
    explicit InitialSettings(QWidget *parent = nullptr);
    ~InitialSettings();
public slots:
    void setLanguageSlot();
    void setColorThemeSlot();

private:
    Ui::InitialSettings *ui;

private:
    enum class language{
        ENGLISH,
        RUSSIAN
    };
    enum class colorTheme{
        DARK,
        LIGHT,
    };
};

#endif // INITIALSETTINGS_H
