# Przykład pliku CMakeLists.txt zgodnego z przygotowanym w ramach pracy 
# inżynierskiej systemem budowania.

cmake_minimum_required(VERSION 2.8)

set(target_name "thread")

# Sprawdzenie, czy komponent nie został już przetworzony.
if(NOT TARGET ${target_name})

    # Ustawienie ścieżki wskazującej na szablony CMake.
    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/../ggss-misc/cmake_templates")

    # Załączenie zawartości wybranych szablonów.
    include(BuildLibrary)
    include(FindLibraryBoost)

    # Pliki nagłówkowe.
    target_include_directories(${target_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/ThreadLib)

    # Dodanie zależności - wykorzystanie szablonu BuildDependencies.
    set(dependency_prefix "${CMAKE_CURRENT_SOURCE_DIR}/..")
    set(dependencies "handle" "log")
    include(BuildDependencies)

endif()
