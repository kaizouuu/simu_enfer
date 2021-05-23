cmake_minimum_required(VERSION 3.17)
project(simu_enfer C)

set(CMAKE_C_STANDARD 11)

add_executable(simu_enfer
        simu_enfer.c
        fonctions_damnes.c
        torture.c
        simulateur.c)
