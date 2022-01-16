set(CommonLibrary_SRS
        ToolLog.cpp
        )

set(CommonLibrary_HEADERS
        ToolLog.h
        )

add_library(CommonLibrary SHARED ${CommonLibrary_SRS})
install(TARGETS CommonLibrary LIBRARY DESTINATION lib)
install(FILES ${CommonLibrary_HEADERS} DESTINATION include/common)
target_link_libraries(CommonLibrary
        Qt${QT_VERSION_MAJOR}::Widgets
        ${THIRD_PARTY_DIR}/glog/lib/libglog.dll.a
        )
target_include_directories(CommonLibrary SYSTEM PUBLIC
        ${THIRD_PARTY_DIR}/glog/include
        ${CMAKE_SOURCE_DIR}/src/common
        )