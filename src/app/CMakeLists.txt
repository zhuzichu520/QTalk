project(qtalk)
add_executable(qtalk main.cpp)
target_link_libraries(qtalk
        Qt${QT_VERSION_MAJOR}::Widgets
        IMLibrary
        UILibrary
        CommonLibrary
        )
install(TARGETS qtalk DESTINATION bin)

target_compile_definitions(qtalk PRIVATE
        GLOG_NO_ABBREVIATED_SEVERITIES
        )