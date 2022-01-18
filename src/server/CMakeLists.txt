project(qServer)
add_executable(qServer main.cpp)
target_link_libraries(qServer
        Qt${QT_VERSION_MAJOR}::Widgets
        IMLibrary
        UILibrary
        CommonLibrary
        )
install(TARGETS qServer DESTINATION bin)

target_compile_definitions(qServer PRIVATE
        GLOG_NO_ABBREVIATED_SEVERITIES
        )