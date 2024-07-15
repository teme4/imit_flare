cmake_minimum_required(VERSION 3.20)

add_subdirectory(CMSIS)

set(SOURCE_FILES_
    ${CMAKE_CURRENT_SOURCE_DIR}/gpio.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/delay.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hardware_config.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set(HEADERS_FILES_
${CMAKE_CURRENT_SOURCE_DIR}/gpio.hpp
${CMAKE_CURRENT_SOURCE_DIR}/delay.hpp
${CMAKE_CURRENT_SOURCE_DIR}/hardware_config.hpp
${CMAKE_CURRENT_SOURCE_DIR}/main.hpp
)
#*********************************************************************************************************************************************#
#*******************************************************{ Build Executable file }*************************************************************#
#*********************************************************************************************************************************************#
set(MyPROJECT "${PROJECT_NAME}.elf")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
add_executable(${MyPROJECT})
target_sources(${MyPROJECT} PUBLIC ${SOURCE_FILES_} ${HEADERS_FILES_})

target_include_directories(${MyPROJECT} PUBLIC
                                        ${CMAKE_CURRENT_SOURCE_DIR}/
                                        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/
                                        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/Device/ST/STM32F1xx/Include/
                                        ${CMAKE_CURRENT_SOURCE_DIR}/CMSIS/Core/Inc
)

target_link_libraries(${MyPROJECT} PUBLIC
                                        cmsis
)



function(convert_to_hex TARGET)
    add_custom_command(
    	TARGET ${TARGET} POST_BUILD
    	COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.hex
    	BYPRODUCTS ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.hex
    )
endfunction()

function(convert_to_bin TARGET)
    add_custom_command(
    	TARGET ${TARGET} POST_BUILD
    	COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:${PROJECT_NAME}.elf> ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.bin
    	BYPRODUCTS ${EXECUTABLE_OUTPUT_PATH}/${PROJECT_NAME}.bin
    )
endfunction()



convert_to_hex(${MyPROJECT})
convert_to_bin(${MyPROJECT})
