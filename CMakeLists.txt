cmake_minimum_required(VERSION 3.16)

project(desafio2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(desafio2 main.cpp
    equipo.h
    equipo.cpp
    jugador.h
    jugador.cpp
    partido.h
    partido.cpp
    equipopartido.h
    equipopartido.cpp
    grupo.h
    grupo.cpp
    grupos.h
    grupos.cpp
    fixture.h
    fixture.cpp
    torneo.h
    torneo.cpp
    torneo.cpp
    tabla.h
    tabla.cpp
    global.h
    global.cpp)

include(GNUInstallDirs)
install(TARGETS desafio2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
