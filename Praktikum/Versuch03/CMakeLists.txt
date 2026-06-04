cmake_minimum_required(VERSION 3.10)

# ============================================================================
# Projekt-Konfiguration
# ============================================================================
project(Versuch03)

# Verwendung des modernen C++ Standards (C++17 wird empfohlen)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================================
# Ausfuehrbare Datei (Executable) definieren
# ============================================================================
# Hier werden alle .cpp Quelldateien zusammengefuehrt.
# Wichtig: Die Header-Dateien (.h) müssen hier nicht zwingend aufgelistet werden, 
# da sie ueber #include in den .cpp Dateien eingebunden werden.
add_executable(OthelloGame 
    othello.cpp 
    othelloKI.cpp 
    test.cpp
)

# ============================================================================
# Compiler-Optionen (Optional, aber hilfreich fuer die Fehlersuche)
# ============================================================================
if(MSVC)
    # Warnungen fuer Microsoft Visual Studio Compiler aktivieren
    target_compile_options(OthelloGame PRIVATE /W4)
else()
    # Warnungen fuer GCC (Linux) und Clang (macOS) aktivieren
    target_compile_options(OthelloGame PRIVATE -Wall -Wextra)
endif()