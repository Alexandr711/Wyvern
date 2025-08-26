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


qt_add_library(UiLib STATIC MenuBar/FileMenu.h MenuBar/FileMenu.cpp
             MainWindow/MainWindow.h MainWindow/MainWindow.cpp
             ToolBars/MainToolBar.h ToolBars/MainToolBar.cpp
             Gui.h Gui.cpp
             MenuBar/HelpMenu.h MenuBar/HelpMenu.cpp
             ToolBars/CADToolsToolBar.h ToolBars/CADToolsToolBar.cpp
             ToolBars/PlanToolsWidget.h ToolBars/PlanToolsWidget.cpp
             Settings.h Settings.cpp
             InitialSettings.h InitialSettingss.cpp InitialSettings.ui
)


target_link_libraries(UiLib PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(UiLib PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(UiLib PRIVATE Qt${QT_VERSION_MAJOR}::Gui)

