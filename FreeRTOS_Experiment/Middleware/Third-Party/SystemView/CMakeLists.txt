cmake_minimum_required(VERSION 3.22)

# Configuring SEGGER SystemView
message("Incorporating SEGGER SystemView.")

# SystemView core source files
set(SYSTEMVIEW_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Sample/FreeRTOSV11/SEGGER_SYSVIEW_FreeRTOS.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Sample/FreeRTOSV11/Config/Cortex-M/SEGGER_SYSVIEW_Config_FreeRTOS.c
    ${CMAKE_CURRENT_SOURCE_DIR}/SYSVIEW/SEGGER_SYSVIEW.c
)

# SystemView public include directories
set(SYSTEMVIEW_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/Config
    ${CMAKE_CURRENT_SOURCE_DIR}/Sample/FreeRTOSV11
    ${CMAKE_CURRENT_SOURCE_DIR}/SEGGER
    ${CMAKE_CURRENT_SOURCE_DIR}/SYSVIEW
)

# Create SystemView library as an INTERFACE library
add_library(SystemView_interface INTERFACE)
target_include_directories(SystemView_interface INTERFACE
    ${SYSTEMVIEW_INCLUDE_DIRS}
)
target_link_libraries(SystemView_interface INTERFACE 
    RTT_interface
)

# Create SystemView library as an OBJECT library
add_library(SystemView OBJECT
    ${SYSTEMVIEW_SOURCES}
)

# Set include directories for SystemView library
target_include_directories(SystemView PUBLIC
    ${SYSTEMVIEW_INCLUDE_DIRS}
)

# Link with stm32cubemx interface library to get HAL and CMSIS includes/defines
# For OBJECT libraries in CMake 3.12+, this propagates INTERFACE properties
target_link_libraries(SystemView PUBLIC 
    RTT_interface
    FreeRTOS_interface
)
