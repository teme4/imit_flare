cmake_minimum_required(VERSION 3.20)

add_library(cmsis)
target_sources(
  cmsis
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/syscalls.c
         ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/sysmem.c
         ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/system_stm32f1xx.c
         ${CMAKE_CURRENT_SOURCE_DIR}/Core/Startup/startup_stm32f103xb.c)

target_include_directories(
  cmsis
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Device/ST/STM32F1xx/Include
         ${CMAKE_CURRENT_SOURCE_DIR}/Include
         ${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc)
message(${CMAKE_CURRENT_SOURCE_DIR}/Device/ST/STM32F1xx/Include)
target_include_directories(cmsis PUBLIC .)

set_target_properties(
  cmsis
  PROPERTIES
    PUBLIC_HEADER
    ${CMAKE_CURRENT_SOURCE_DIR}/Device/ST/STM32F1xx/Include/stm32f103xb.h)
