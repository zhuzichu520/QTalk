set(IMLibrary_SRS
        interfaces/IControlCenter.cpp
        interfaces/IConnection.cpp
        interfaces/IServer.cpp
        ControlCenter.cpp
        ControlCenterPrivate.cpp
        Connection.cpp
        MessageServer.cpp
        )

set(IMLibrary_Interfaces_HEADERS
        interfaces/IControlCenter.h
        interfaces/IConnection.h
        interfaces/IServer.h
        )

set(IMLibrary_HEADERS
        ControlCenter.h
        ControlCenterPrivate.h
        Connection.h
        MessageServer.h
        )

add_library(IMLibrary SHARED ${IMLibrary_SRS})
install(TARGETS IMLibrary LIBRARY DESTINATION lib)
install(FILES ${IMLibrary_Interfaces_HEADERS} DESTINATION include/qtalk/interfaces)
install(FILES ${IMLibrary_HEADERS} DESTINATION include/qtalk)
target_link_libraries(IMLibrary
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Network
        ${THIRD_PARTY_DIR}/openssl/lib/libssl.lib
        ${THIRD_PARTY_DIR}/openssl/lib/libcrypto.lib
        CommonLibrary
        )
target_include_directories(UILibrary SYSTEM PUBLIC
        ${CMAKE_SOURCE_DIR}/src/im
        ${THIRD_PARTY_DIR}/openssl/include
        )