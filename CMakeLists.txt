project(IndieStudio)
cmake_minimum_required(VERSION 3.7)
set(CMAKE_MODULE_PATH "/usr/lib/OGRE/cmake/")
#set(CMAKE_CXX_FLAGS "-Wall -W -Werror -ansi -pedantic -g")
include_directories ("/usr/share/OGRE/Samples/Common/include/")
find_package(OGRE REQUIRED)
include_directories (${OGRE_INCLUDE_DIRS})
# find_package(OIS REQUIRED)
SET(SOURCES
        main.cpp)
add_executable (
        IndieStudio ${SOURCES}
)

target_link_libraries(IndieStudio ${OGRE_LIBRARY} ${OIS_LIBRARY})
