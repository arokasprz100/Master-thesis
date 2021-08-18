# Określenie minimalnej wersji narzędzia CMake.
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# Określenie nazwy i wersji projektu oraz stosowanego języka.
project(SampleApp VERSION 1.0.0 LANGUAGES CXX)

# Dodanie docelowego pliku wykonywanego.
add_executable(Sample main.cpp)
