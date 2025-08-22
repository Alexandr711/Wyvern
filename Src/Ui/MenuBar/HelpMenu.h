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

private:
    QMenu* changeLanguageMenu;
    QAction* englishAction;
    QAction* russianAction;

    QMenu* changeColorThemeMenu;
    QAction* darkColorTheme;
    QAction* lightColorTheme;

    QAction* helpAction;
};

#endif // HELPMENU_H
