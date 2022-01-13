set(qtalk_SRS
    main.cpp
    MainWindow.cpp
)

set(qtalk_HEADERS
    MainWindow.h
)

set(qtalk_RCC
    qml.qrc
)

add_executable(qtalk ${qtalk_SRS} ${qtalk_RCC})

target_link_libraries(qtalk
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::QuickControls2
    )
