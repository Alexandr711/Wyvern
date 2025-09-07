#Creating lib for GUI

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
qt_standard_project_setup()

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)
find_package(Qt6 REQUIRED COMPONENTS Widgets)


qt_add_library(UiLib STATIC MenuBar/FileMenu.h MenuBar/FileMenu.cpp
             MainWindow/MainWindow.h MainWindow/MainWindow.cpp
             ToolBars/MainToolBar.h ToolBars/MainToolBar.cpp
             Gui.h Gui.cpp
             MenuBar/HelpMenu.h MenuBar/HelpMenu.cpp

             Settings.h Settings.cpp
             InitialSettings.h InitialSettingss.cpp InitialSettings.ui
             SettingValues.h
             Dialogs/OpenDialog.h Dialogs/OpenDialog.cpp
             Dialogs/CreateDialog.h Dialogs/CreateDialog.cpp Dialogs/CreateDialog.ui



             ToolBars/CADToolBar.h ToolBars/CADToolBar.cpp
             ToolBars/CADTools/CAD3DToolsWidget.h ToolBars/CADTools/CAD3DToolsWidget.cpp
)


target_link_libraries(UiLib PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(UiLib PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(UiLib PRIVATE Qt${QT_VERSION_MAJOR}::Gui)
target_link_libraries(UiLib PRIVATE Qt6::Widgets)

