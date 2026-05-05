cmake_minimum_required(VERSION 3.16)

project(ShellInventory VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core Sql)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appShellInventory
    main.cpp
)

qt_add_qml_module(appShellInventory
    URI ShellInventory
    VERSION 1.0
    QML_FILES
        Main.qml
        qml/InventoryTable.qml

        # components
        qml/components/Cell.qml

        # pages
        qml/pages/HistoryPage.qml
        qml/pages/EditPage.qml
    SOURCES
        includes/inventorymanager.h src/inventorymanager.cpp
        includes/inventorylistmodel.h src/inventorylistmodel.cpp
        includes/historylistmodel.h src/historylistmodel.cpp
        includes/databasemanager.h src/databasemanager.cpp
        includes/historyfilterlistmodel.h src/historyfilterlistmodel.cpp
        includes/inventorysortlistmodel.h src/inventorysortlistmodel.cpp
)

target_include_directories(appShellInventory PRIVATE
        ${CMAKE_SOURCE_DIR}/includes
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appShellInventory PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appShellInventory
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appShellInventory
    PRIVATE Qt6::Quick
)
target_link_libraries(appShellInventory PRIVATE Qt6::Core Qt6::Sql)

include(GNUInstallDirs)
install(TARGETS appShellInventory
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
