#ifndef HELPMENU_H
#define HELPMENU_H

#include <QMenu>
#include <QAction>
#include <QString>

class HelpMenu: public QMenu
{
public:
    HelpMenu(QWidget* parent = nullptr);
    ~HelpMenu();

    void setItems();

    inline void changeLanguageMenuSetTitle(QString title){changeLanguageMenu->setTitle(title);}
    inline void changeColorThemeMenuSetTitle(QString title){changeColorThemeMenu->setTitle(title);}
    inline void darkColorThemeSetTitle(QString title){darkColorTheme->setText(title);}
    inline void lightColorThemeSetTitle(QString title){lightColorTheme->setText(title);}
    inline void helpActionSetTitle(QString title){helpAction->setText(title);}
    inline void systemDarkColorSetTitle(QString title){systemDarkColor->setText(title);}
    inline void systemLightColorSetTitle(QString title){systemLightColor->setText(title);}

    inline QAction* englishActionGet(){return englishAction;}
    inline QAction* russianActionGet(){return russianAction;}
    inline QAction* darkColorThemeGet(){return darkColorTheme;}
    inline QAction* lightColorThemeGet(){return lightColorTheme;}
    inline QAction* systemDarkColorGet(){return systemDarkColor;}
    inline QAction* systemLightColorGet(){return systemLightColor;}

    void setLanguageActions();
    void setColorThemeAction();

private:
    QMenu* changeLanguageMenu;
    QAction* englishAction;
    QAction* russianAction;

    QMenu* changeColorThemeMenu;
    QAction* darkColorTheme;
    QAction* lightColorTheme;
    QAction* systemDarkColor;
    QAction* systemLightColor;

    QAction* helpAction;

private:
    bool english;
    bool russian;

    bool darkTheme;
    bool lightTheme;
    bool systemDarkTheme;
    bool systemLightTheme;
};

inline void HelpMenu::setLanguageActions()
{

}

inline void HelpMenu::setColorThemeAction()
{

}

#endif // HELPMENU_H
