cmake_minimum_required(VERSION 2.8)
project(ggss-thread-lib)

# Załączenie szablonów CMake zawierających wykorzystywane funkcje.
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../ggss-util-libs/cmake-templates")
include(BuildStaticLibrary)     # ggss_build_static_library

# Funkcja tworząca bibliotekę statyczną.
ggss_build_static_library(
    TARGET_NAME "thread"
    DEPENDENCY_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/.."
    DEPENDENCIES "sigslot" "ggss-util-libs/log"
)
