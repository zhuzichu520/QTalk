project(qTalk)
add_executable(qTalk main.cpp)
target_link_libraries(qTalk
        Qt${QT_VERSION_MAJOR}::Widgets
        IMLibrary
        UILibrary
        CommonLibrary
        )
install(TARGETS qTalk DESTINATION bin)

target_compile_definitions(qTalk PRIVATE
        GLOG_NO_ABBREVIATED_SEVERITIES
        )