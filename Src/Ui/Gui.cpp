#include <QFile>
#include <QJsonObject>
#include <QFileInfo>

#include "Gui.h"
#include "MainWindow/MainWindow.h"
#include "MenuBar/FileMenu.h"
#include "MenuBar/HelpMenu.h"
#include "ToolBars/MainToolBar.h"
#include "ToolBars/CADToolsToolBar.h"
#include "Settings.h"
#include "SettingValues.h"


Gui::Gui()
{
    settings = new Settings;
    mainWindow = new MainWindow;

    menuBar = new QMenuBar;
    fileMenu = new FileMenu;
    helpMenu = new HelpMenu;

    mainToolBar = new MainToolBar;

    cadToolsToolBar = new CADToolsToolBar;
}

Gui::~Gui()
{
    delete cadToolsToolBar;

    delete mainToolBar;

    delete helpMenu;
    delete fileMenu;
    delete menuBar;

    delete mainWindow;
    delete settings;
}

void Gui::setItems()
{
    mainWindow->setMenuBar(menuBar);

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(helpMenu);
    fileMenu->setItems();
    helpMenu->setItems();

    mainWindow->addToolBar(mainToolBar);
    mainWindow->addToolBarBreak();
    mainWindow->addToolBar(cadToolsToolBar);

    mainToolBar->setItems();
    cadToolsToolBar->setItems();
}

void Gui::setTitleOnWidgets()
{
    settings->readJsonFile("Config.json");

    //Open config.json file
    QJsonObject configJsonObject = settings->getJsonObject();

    //Open json file whith language settings
    settings->readJsonFile(configJsonObject["Language"].toString());
    QJsonObject tempJsonObject = settings->getJsonObject();



    //Menu bar titles
    //Menu "File"
    fileMenu->setTitle(tempJsonObject["File"].toString());
    fileMenu->createMenuSetTitle(tempJsonObject["Create"].toString());
    fileMenu->createFileActionSetTitle(tempJsonObject["Create file"].toString());
    fileMenu->createProjectActionSetTitle(tempJsonObject["Create project"].toString());
    fileMenu->openMenuSetTitle(tempJsonObject["Open"].toString());
    fileMenu->openFileActionSetTitle(tempJsonObject["Open file"].toString());
    fileMenu->openProjectActionSetTitle(tempJsonObject["Open project"].toString());

    //Menu "Help"
    helpMenu->setTitle(tempJsonObject["Help"].toString());
    helpMenu->changeLanguageMenuSetTitle(tempJsonObject["Language"].toString());
    helpMenu->changeColorThemeMenuSetTitle(tempJsonObject["Color theme"].toString());
    helpMenu->darkColorThemeSetTitle(tempJsonObject["Dark theme"].toString());
    helpMenu->lightColorThemeSetTitle(tempJsonObject["Light theme"].toString());
    helpMenu->helpActionSetTitle(tempJsonObject["Help action"].toString());


    //Main ToolBar
    mainToolBar->setOpenButtonToolTipTitle(tempJsonObject["Open tooltip"].toString());
    mainToolBar->setCreateButtonToolTipTitle(tempJsonObject["Create tooltip"].toString());
    mainToolBar->setSaveButtonToolTipTitle(tempJsonObject["Save tooltip"].toString());
    mainToolBar->setSaveAllButtonToolTipTitle(tempJsonObject["Save all tooltip"].toString());
    mainToolBar->setUndoButtonToolTipTitle(tempJsonObject["Undo tooltip"].toString());
    mainToolBar->setReturnButtonToolTipTitle(tempJsonObject["Return tooltip"].toString());

    //CADToolsToolBar
    cadToolsToolBar->lineButtonSetTitle(tempJsonObject["Line tooltip"].toString());
    cadToolsToolBar->arcButtonSetTitle(tempJsonObject["Arc tooltip"].toString());
    cadToolsToolBar->polylineButtonSetTitle(tempJsonObject["Polyline tooltip"].toString());
    cadToolsToolBar->circleButtonSetTitle(tempJsonObject["Circle tooltip"].toString());
    cadToolsToolBar->rectangleButtonSetTitle(tempJsonObject["Rectangle tooltip"].toString());
}



void Gui::setFlags()
{
    settings->readJsonFile("Config.json");

    //Open config.json file
    QJsonObject configJsonObject = settings->getJsonObject();

    //Set flags for menu "Help"
    helpMenu->setRussianActionFlag(configJsonObject["Russian flag"].toBool());
    helpMenu->setEnglishActionFlag(configJsonObject["English flag"].toBool());
    helpMenu->setDarkThemeActionFlag(configJsonObject["Dark flag"].toBool());
    helpMenu->setLightThemeActionFlag(configJsonObject["Light flag"].toBool());
}

void Gui::connections()
{
    //Connect for change languages
    connect(helpMenu->russianActionGet(), SIGNAL(triggered(bool)), this, SLOT(setRussianSlot()));
    connect(helpMenu->englishActionGet(), SIGNAL(triggered(bool)), this, SLOT(setEnglishSlot()));
    //Connect for change color theme
    connect(helpMenu->darkColorThemeGet(), SIGNAL(triggered(bool)), this, SLOT(setDarkThemeSlot()));
    connect(helpMenu->lightColorThemeGet(), SIGNAL(triggered(bool)), this, SLOT(setLightThemeSlot()));
}

void Gui::setColorTheme()
{
    //Open config file
    settings->readJsonFile("Config.json");
    QJsonObject configJsonObject = settings->getJsonObject();
    QString colorThemeFileString = configJsonObject["Theme"].toString();

    //Open color theme file
    settings->readJsonFile(colorThemeFileString);
    configJsonObject = settings->getJsonObject();


    //Set style sheets
    mainToolBar->setStyleSheet(QString(settings->readQssFile(configJsonObject["MainToolBar"].toString())));
}


void Gui::show()
{
    mainWindow->showMaximized();
}

void Gui::setRussianSlot()
{
    settings->readJsonFile("Config.json");
    QJsonObject settingJsonObject = settings->getJsonObject();
    settingJsonObject.insert("Language", RUSSIAN_JSON_FILE);
    settingJsonObject.insert("English flag", false);
    settingJsonObject.insert("Russian flag", true);
    settings->setJsonObject(settingJsonObject);
    settings->writeJsonFile("Config.json");
    setTitleOnWidgets();
    helpMenu->setEnglishActionFlag(false);
    helpMenu->setRussianActionFlag(true);
}

void Gui::setEnglishSlot()
{
    settings->readJsonFile("Config.json");
    QJsonObject settingJsonObject = settings->getJsonObject();
    settingJsonObject.insert("Language", ENGLISH_JSON_FILE);
    settingJsonObject.insert("Russian flag", false);
    settingJsonObject.insert("English flag", true);
    settings->setJsonObject(settingJsonObject);
    settings->writeJsonFile("Config.json");
    setTitleOnWidgets();
    helpMenu->setEnglishActionFlag(true);
    helpMenu->setRussianActionFlag(false);
}

void Gui::setDarkThemeSlot()
{
    settings->readJsonFile("Config.json");
    QJsonObject settingJsonObject = settings->getJsonObject();
    settingJsonObject.insert("Theme", ":/ColorThemes/Src/Ui/Styles/DarkStyle/DarkStyle.json");
    settingJsonObject.insert("Light flag", false);
    settingJsonObject.insert("Dark flag", true);
    settings->setJsonObject(settingJsonObject);
    settings->writeJsonFile("Config.json");
    setColorTheme();
    helpMenu->setDarkThemeActionFlag(true);
    helpMenu->setLightThemeActionFlag(false);
}

void Gui::setLightThemeSlot()
{
    settings->readJsonFile("Config.json");
    QJsonObject settingJsonObject = settings->getJsonObject();
    settingJsonObject.insert("Theme", ":/ColorThemes/Src/Ui/Styles/LightStyle/LightStyle.json");
    settingJsonObject.insert("Light flag", true);
    settingJsonObject.insert("Dark flag", false);
    settings->setJsonObject(settingJsonObject);
    settings->writeJsonFile("Config.json");
    setColorTheme();
    helpMenu->setDarkThemeActionFlag(false);
    helpMenu->setLightThemeActionFlag(true);
}
