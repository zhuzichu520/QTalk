set(IMLibrary_SRS
    interfaces/IControlCenter.cpp
    ControlCenter.cpp
    )

set(IMLibrary_Interfaces_HEADERS
    interfaces/IControlCenter.h
    )

set(IMLibrary_HEADERS
    ControlCenter.h
    )

add_library(IMLibrary SHARED ${IMLibrary_SRS})
install(TARGETS IMLibrary LIBRARY DESTINATION lib)
install(FILES ${IMLibrary_Interfaces_HEADERS} DESTINATION include/qtalk/interfaces)
install(FILES ${IMLibrary_HEADERS} DESTINATION include/qtalk)
target_link_libraries(IMLibrary
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Network
    )
