project(inputstream.nxmsl)

cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR})

enable_language(CXX)

find_package(Kodi REQUIRED)
find_package(kodiplatform REQUIRED)
find_package(p8-platform REQUIRED)

set(NXMSL_SOURCES 
	src/main.cpp
	src/manifest/tree.cpp
	src/manifest/stream.cpp
	src/helpers.cpp
)

list(APPEND DEPLIBS ${p8-platform_LIBRARIES})

include_directories(${INCLUDES}
                    ${kodiplatform_INCLUDE_DIRS}
                    ${p8-platform_INCLUDE_DIRS}
                    ${KODI_INCLUDE_DIR}
                    lib/libbento4/Core
)
                    
if(WIN32)
	list(APPEND DEPLIBS ws2_32)
else()
	add_definitions(-D__STDC_FORMAT_MACROS)
endif()

add_subdirectory(lib/libbento4)
list(APPEND DEPLIBS bento4)
					
build_addon(inputstream.nxmsl NXMSL DEPLIBS)

include(CPack)
