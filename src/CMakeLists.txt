add_subdirectory(app)
add_subdirectory(server)
add_subdirectory(ui)
add_subdirectory(im)
add_subdirectory(common)

set(OPENSSL_DLL
        ${THIRD_PARTY_DIR}/openssl/bin/libcrypto-1_1-x64.dll
        ${THIRD_PARTY_DIR}/openssl/bin/libssl-1_1-x64.dll
        ${THIRD_PARTY_DIR}/openssl/bin/openssl.exe
        )

install(FILES ${OPENSSL_DLL} DESTINATION bin)

set(GLOG_DLL
        ${THIRD_PARTY_DIR}/glog/bin/libglog.dll
        )

install(FILES ${GLOG_DLL} DESTINATION bin)
