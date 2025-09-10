#include <QFile>
#include <QJsonObject>
#include <QFileInfo>

#include "Gui.h"
#include "MainWindow/MainWindow.h"
#include "MenuBar/FileMenu.h"
#include "MenuBar/HelpMenu.h"
#include "ToolBars/MainToolBar.h"
#include "Settings.h"
#include "SettingValues.h"
#include "Dialogs/CreateDialog.h"
#include "Dialogs/OpenDialog.h"
#include "ToolBars/CADToolBar.h"
#include "ToolBars/CADTools/CAD3DToolsWidget.h"
#include "ToolBars/CADTools/DrawToolsWidget.h"


Gui::Gui()
{
    settings = new Settings;
    mainWindow = new MainWindow;

    menuBar = new QMenuBar(mainWindow);
    fileMenu = new FileMenu(menuBar);
    helpMenu = new HelpMenu(menuBar);

    mainToolBar = new MainToolBar;

    openDialog = new OpenDialog(mainWindow);
    createDialog = new CreateDialog();

    cadToolBar = new CADToolBar;
    cad3DToolsWidget = new CAD3DToolsWidget;
    drawToolsWidget = new DrawToolsWidget;
}

Gui::~Gui()
{
    delete drawToolsWidget;
    delete cad3DToolsWidget;
    delete cadToolBar;

    delete createDialog;

    delete mainToolBar;

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
    mainToolBar->setMovable(false);

    mainToolBar->setItems();

    //Add CADToolBar
    mainWindow->addToolBar(cadToolBar);
    cadToolBar->setMovable(false);
    cadToolBar->setItems();
    cadToolBar->addPlanTab(drawToolsWidget);
    cadToolBar->addCad3DToolsTab(cad3DToolsWidget);
    cad3DToolsWidget->setItems();
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

    //Set title on CAD ToolBar
    cadToolBar->setPlanString(tempJsonObject["Drawing"].toString());
    cadToolBar->setCad3DToolsString(tempJsonObject["3DTools"].toString());
    cadToolBar->setTabsText();

    cad3DToolsWidget->setToolTipLineButton(tempJsonObject["Line"].toString());
    cad3DToolsWidget->setToolTipArcButton(tempJsonObject["Arc"].toString());
    cad3DToolsWidget->setToolTipPolylineButton(tempJsonObject["Polyline"].toString());
    cad3DToolsWidget->setToolTipCircleButton(tempJsonObject["Circle"].toString());
    cad3DToolsWidget->setToolTipRectangleButton(tempJsonObject["Rectangle"].toString());

    cad3DToolsWidget->setSphereString(tempJsonObject["Sphere"].toString());
    cad3DToolsWidget->setCilindrString(tempJsonObject["Cylinder"].toString());
    cad3DToolsWidget->setParallelepipedString(tempJsonObject["Parallelepiped"].toString());
    cad3DToolsWidget->setConeString(tempJsonObject["Cone"].toString());
    cad3DToolsWidget->setPyramidString(tempJsonObject["Pyramid"].toString());
    cad3DToolsWidget->setTorusString(tempJsonObject["Torus"].toString());

    cad3DToolsWidget->setItemsText();
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

    connect(mainToolBar->getOpenButton(), SIGNAL(clicked(bool)), this, SLOT(openOpenDialogSlot()));
    connect(mainToolBar->getCreateButton(), SIGNAL(clicked(bool)), this, SLOT(openCreateDialogSlot()));
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
    menuBar->setStyleSheet(QString(settings->readQssFile(configJsonObject["MenuBar"].toString())));
    mainToolBar->setStyleSheet(QString(settings->readQssFile(configJsonObject["MainToolBar"].toString())));
    fileMenu->setStyleSheet(QString(settings->readQssFile(configJsonObject["Menu"].toString())));
    helpMenu->setStyleSheet(QString(settings->readQssFile(configJsonObject["Menu"].toString())));
    cadToolBar->setStyleSheet(QString(settings->readQssFile(configJsonObject["CADToolBar"].toString())));
    cad3DToolsWidget->setStyleSheet(QString(settings->readQssFile(configJsonObject["3DToolsTab"].toString())));

    qDebug() <<configJsonObject["FigureComboBox"].toString();
    settings->readJsonFile(configJsonObject["FigureComboBox"].toString());
    QJsonObject FigureComboBoxIconJson = settings->getJsonObject();
    cad3DToolsWidget->setSphereIcon(FigureComboBoxIconJson["Sphere"].toString());
    cad3DToolsWidget->setCilindrIcon(FigureComboBoxIconJson["Cylinder"].toString());
    cad3DToolsWidget->setParallelepipedIcon(FigureComboBoxIconJson["Parallelepiped"].toString());
    cad3DToolsWidget->setConeIcon(FigureComboBoxIconJson["Cone"].toString());
    cad3DToolsWidget->setPyramidIcon(FigureComboBoxIconJson["Pyramid"].toString());
    cad3DToolsWidget->setTorusIcon(FigureComboBoxIconJson["Torus"].toString());
    cad3DToolsWidget->setItemsIcons();
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

void Gui::openOpenDialogSlot()
{
    openDialog->show();
}

void Gui::openCreateDialogSlot()
{
    createDialog->setWindowModality(Qt::ApplicationModal);
    createDialog->show();
}


