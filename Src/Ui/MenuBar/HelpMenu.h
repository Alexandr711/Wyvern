#ifndef HELPMENU_H
#define HELPMENU_H

#include <QMenu>
#include <QAction>

class HelpMenu: public QMenu
{
public:
    HelpMenu(QWidget* parent = nullptr);
    ~HelpMenu();

    void setItems();

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
