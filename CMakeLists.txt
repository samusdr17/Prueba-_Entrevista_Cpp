cmake_minimum_required(VERSION 3.10)

project(ProyectoProfesional)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Prueba_Entrevista_Cpp ${SOURCES})
add_custom_command(TARGET Prueba_Entrevista_Cpp POST_BUILD
    COMMAND chmod +x Prueba_Entrevista_Cpp
)
