set(CPACK_PACKAGE_NAME "${QFM1000_APPLICATION_NAME}")
set(CPACK_PACKAGE_VENDOR "${QFM1000_ORGANIZATION_NAME}")

set(CPACK_PACKAGE_VERSION_MAJOR "${QFM1000_APPLICATION_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${QFM1000_APPLICATION_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${QFM1000_APPLICATION_VERSION_PATCH}")

set(CPACK_PACKAGE_VERSION "${QFM1000_APPLICATION_VERSION}")
set(CPACK_PACKAGE_CONTACT "sadylan@gmail.com")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Simple tool for editing channels and configuration parameters of Philips FM1000 radio.")
set(CPACK_PACKAGE_EXECUTABLES qfm1000 "qFM1000")

#set(CPACK_RESOURCE_FILE_LICENSE "LICENSE.txt")
#set(CPACK_RESOURCE_FILE_README "README.txt")
#set(CPACK_RESOURCE_FILE_WELCOME "WELCOME.txt")

list(APPEND CPACK_COMPONENTS_ALL qfm1000)

set(CPACK_COMPONENT_QFM1000_DISPLAY_NAME "qFM1000")
set(CPACK_COMPONENT_QFM1000_DESCRIPTION "Simple tool for editing channels and configuration parameters of Philips FM1000 radio.")
set(CPACK_COMPONENT_QFM1000_REQUIRED TRUE)

if (WIN32 OR APPLE)
    list(APPEND CPACK_COMPONENTS_ALL qtlibs)
    set(CPACK_COMPONENT_QTLIBS_DISPLAY_NAME "Qt libs")
    set(CPACK_COMPONENT_QTLIBS_DESCRIPTION "Needed Qt libraries")
    set(CPACK_COMPONENT_QTLIBS_REQUIRED TRUE)

    list(APPEND CPACK_COMPONENT_FDOTOOL_DEPENDS qtlibs)
endif ()

if (UNIX AND NOT APPLE)
    set(CPACK_GENERATOR "DEB")

    execute_process(COMMAND dpkg --print-architecture
            OUTPUT_VARIABLE CPACK_DEBIAN_PACKAGE_ARCHITECTURE
            OUTPUT_STRIP_TRAILING_WHITESPACE)

    set(CPACK_DEBIAN_PACKAGE_SECTION "misc")
    set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
    set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS TRUE)

    set(CPACK_PACKAGE_FILE_NAME "qfm1000-${CPACK_PACKAGE_VERSION}-${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}")
elseif (WIN32)
    set(CPACK_GENERATOR "WIX")

    set(CPACK_WIX_PRODUCT_GUID "A54CC844-1C6A-4C4B-9C5A-C4BB58C9454C")
    set(CPACK_WIX_UPGRADE_GUID "E6D59A10-31FD-4512-868C-4F86EF50950F")
    set(CPACK_WIX_PROPERTY_ARPHELPLINK "https://github.com/sardylan/qfm1000")
    set(CPACK_WIX_PROPERTY_ARPSIZE "0")

    set(CPACK_PACKAGE_INSTALL_DIRECTORY "qFM1000 ${CPACK_PACKAGE_VERSION}")
    set(CPACK_PACKAGE_ICON "icons/windows/icon-256.ico")

    set(CPACK_PACKAGE_FILE_NAME "qfm1000-${CPACK_PACKAGE_VERSION}")
elseif (APPLE)
    #    set(CPACK_GENERATOR "OSXX11")
    set(CPACK_GENERATOR "Bundle")

    set(CPACK_PACKAGE_FILE_NAME "qfm1000-${CPACK_PACKAGE_VERSION}")
endif ()

include(CPack)
