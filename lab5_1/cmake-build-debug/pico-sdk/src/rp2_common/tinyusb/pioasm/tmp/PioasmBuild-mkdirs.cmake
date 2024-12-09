# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/program/Pico-SDK-v1.5.0/pico-sdk/tools/pioasm"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab5_1/cmake-build-debug/pioasm"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab5_1/cmake-build-debug/pico-sdk/src/rp2_common/tinyusb/pioasm"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab5_1/cmake-build-debug/pico-sdk/src/rp2_common/tinyusb/pioasm/tmp"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab5_1/cmake-build-debug/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab5_1/cmake-build-debug/pico-sdk/src/rp2_common/tinyusb/pioasm/src"
  "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab5_1/cmake-build-debug/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab5_1/cmake-build-debug/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/program_files/metropolia_file/2nd/Embedded_Systems_Programming/assignment/lab5_1/cmake-build-debug/pico-sdk/src/rp2_common/tinyusb/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
