project(qtalk)
add_executable(qtalk main.cpp)
target_link_libraries(qtalk
        Qt${QT_VERSION_MAJOR}::Widgets
        IMLibrary UILibrary
        )
install(TARGETS qtalk DESTINATION bin)
