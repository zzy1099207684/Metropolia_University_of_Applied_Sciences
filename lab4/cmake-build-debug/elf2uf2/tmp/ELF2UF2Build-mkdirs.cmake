# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/program/Pico-SDK-v1.5.0/pico-sdk/tools/elf2uf2"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab4/cmake-build-debug/elf2uf2"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab4/cmake-build-debug/elf2uf2"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab4/cmake-build-debug/elf2uf2/tmp"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab4/cmake-build-debug/elf2uf2/src/ELF2UF2Build-stamp"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab4/cmake-build-debug/elf2uf2/src"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab4/cmake-build-debug/elf2uf2/src/ELF2UF2Build-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab4/cmake-build-debug/elf2uf2/src/ELF2UF2Build-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab4/cmake-build-debug/elf2uf2/src/ELF2UF2Build-stamp${cfgdir}") # cfgdir has leading slash
endif()
