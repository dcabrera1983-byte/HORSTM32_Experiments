cmake_minimum_required(VERSION 3.22)

# FreeRTOS Library Configuration
# This configures FreeRTOS v11.1 for STM32F767 (ARM Cortex-M7)
message("Incorporating FreeRTOS CMake.")

# FreeRTOS core source files
set(FREERTOS_CORE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/croutine.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/event_groups.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/queue.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/stream_buffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/tasks.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/timers.c
)

# FreeRTOS portable layer (ARM Cortex-M7 with GCC)
set(FREERTOS_PORTABLE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/portable/GCC/ARM_CM7/r0p1/port.c
)

# FreeRTOS memory management (heap_4)
set(FREERTOS_MEMMANG_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/portable/MemMang/heap_4.c
)

# FreeRTOS integration wrapper (if present)
set(FREERTOS_WRAPPER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Src/freertos.c
)

# FreeRTOS public include directories
set(FREERTOS_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Source/portable/GCC/ARM_CM7/r0p1
)

# FreeRTOS configuration include directory
set(FREERTOS_CONFIG_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/Config/Inc
)

add_library(FreeRTOS_interface INTERFACE)
target_include_directories(FreeRTOS_interface INTERFACE
    ${FREERTOS_INCLUDE_DIRS}
    ${FREERTOS_CONFIG_INCLUDE_DIR}
)


# Create FreeRTOS library as an OBJECT library
add_library(FreeRTOS OBJECT
    ${FREERTOS_CORE_SOURCES}
    ${FREERTOS_PORTABLE_SOURCES}
    ${FREERTOS_MEMMANG_SOURCES}
    ${FREERTOS_WRAPPER_SOURCES}
)

# Set include directories for FreeRTOS library
target_include_directories(FreeRTOS PUBLIC
    ${FREERTOS_INCLUDE_DIRS}
    ${FREERTOS_CONFIG_INCLUDE_DIR}
)

# Link with stm32cubemx interface library to get HAL and CMSIS includes/defines
# For OBJECT libraries in CMake 3.12+, this propagates INTERFACE properties
target_link_libraries(FreeRTOS PUBLIC 
    stm32cubemx
    SystemView_interface
)
