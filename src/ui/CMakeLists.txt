set(UILibrary_SRS
        MainWindow.cpp
        UiManager.cpp
        )

set(UILibrary_HEADERS
        MainWindow.h
        UiManager.h
        )

set(UILibrary_RCC
        qml.qrc
        )

add_library(UILibrary SHARED ${UILibrary_SRS} ${UILibrary_RCC})
install(TARGETS UILibrary LIBRARY DESTINATION lib)
install(FILES ${UILibrary_HEADERS} DESTINATION include/qtalk/ui)
target_link_libraries(UILibrary
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Quick
        Qt${QT_VERSION_MAJOR}::QuickControls2
        IMLibrary

        )
target_include_directories(UILibrary SYSTEM PUBLIC ${CMAKE_SOURCE_DIR}/src/ui)