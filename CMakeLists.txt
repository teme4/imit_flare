cmake_minimum_required(VERSION 3.20)

#!  ************************************************************************************************************************** #!
#!  ********************************************* { GENERAL INFORMATION } **************************************************** #!
#!  ************************************************************************************************************************** #!
set(MCU STM32F103C8)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_SYSTEM_NAME    Generic)
set(CMAKE_SYSTEM_VERSION        1)
set(CMAKE_SYSTEM_PROCESSOR    arm)

#--toolchain--
SET(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
SET(TOOL_EXECUTABLE_SUFFIX ".exe")
SET(CMAKE_C_COMPILER "arm-none-eabi-gcc${TOOL_EXECUTABLE_SUFFIX}")
SET(CMAKE_CXX_COMPILER "arm-none-eabi-g++${TOOL_EXECUTABLE_SUFFIX}")
SET(CMAKE_ASM_COMPILER "arm-none-eabi-gcc${TOOL_EXECUTABLE_SUFFIX}")
SET(CMAKE_OBJCOPY "arm-none-eabi-objcopy${TOOL_EXECUTABLE_SUFFIX}" CACHE STRING "objcopy tool")
SET(CMAKE_OBJDUMP "arm-none-eabi-objdump${TOOL_EXECUTABLE_SUFFIX}" CACHE STRING "objdump tool")
SET(CMAKE_SIZE "arm-none-eabi-size${TOOL_EXECUTABLE_SUFFIX}" CACHE STRING "size tool")

project(imit_flame LANGUAGES C CXX ASM)
enable_language(C CXX ASM)

#!  ************************************************************************************************************************** #!
#!  **************************************************** { OPTIONS } ********************************************************* #!
#!  ************************************************************************************************************************** #!
ADD_DEFINITIONS(
                -DSTM32F103xB
                -DSTM32F1
                # --verbose
                #-DLoggerPrintStages
                #-DStartControlLOGS
                #-DBOB
                #-DStartControlLOGS
                #-DIrps5401_LOGS
                #-DPacketInterface_TypeC
                #-DF_CPU=72000000L

                )
#-- Linker script --------------------------------------------------------------
SET(LDSCRIPT ${CMAKE_SOURCE_DIR}/src/CMSIS/STM32F103C8_FLASH.ld)
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T ${LDSCRIPT} -Wl,-Map=${CMAKE_BINARY_DIR}/${PROJECT_NAME}.map -Wl,--print-memory-usage")


add_compile_options(
                        -Wno-unused-function
                        -Wno-unused-variable
                        -Wno-return-type
                        -Wno-comment
                        -Wno-unused-but-set-variable
                        -Wno-unused-parameter
                        -Wno-unused-value
                        -Wno-unused-label
                        -Wno-narrowing
)
#!  ************************************************************************************************************************** #!
#!  ********************************************* { GLOBAL PROPERTIES } ****************************************************** #!
#!  ************************************************************************************************************************** #!


set_property(GLOBAL PROPERTY
                            C_STANDARD 11
                            #CXX_STANDARD_REQUIRED YES
                            CXX_STANDARD 17
)

#распечатывает defines
get_directory_property(DirDefs COMPILE_DEFINITIONS )
message( "COMPILE_DEFINITIONS = ${DirDefs}" )


#!  ************************************************************************************************************************** #!
#!  ********************************************* { SUBDIRECTORIES } ********************************************************* #!
#!  ************************************************************************************************************************** #!
# include(cmake/BuildType.cmake)                                          #-----> Определение и обработка параметров проекта
#include(cmake/linker/AddExecutableWithLinkerScriptDep.cmake)            #-----> Переопределяет add_executable, чтобы зависимости скрипта компоновщика регистрировались автоматически
#include(cmake/compiler/CheckAndApplyFlags.cmake)                        #-----> Улучшенные функции для проверки поддержки флагов компилятора/компоновщика
# include(cmake/Conversions.cmake)                                        #-----> Предоставляет функции для преобразования файлов ELF в другие форматы
#include(cmake/map.cmake)                                                #-----> Добавляет функцию для создания карты компоновщика
# include(cmake/ProjectINFO.cmake)                                        #-----> Добавляет общую информацию о проекте

add_subdirectory(src) #----->To build executable file

#           FLAGS FROM PLATFORMIO
# -c
# -std=c++1z
# -fno-rtti
# -fno-exceptions
# -funwind-tables
# #-mpoke-function-name
# -Wno-psabi
# -Wformat=0
# -v
# -ffunction-sections
# -fdata-sections
# -Wall
# -mthumb
# -mcpu=cortex-m3
# -Og
# -g2
# -ggdb2
