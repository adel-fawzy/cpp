cmake_minimum_required(VERSION 3.16)

project(observer-mediator LANGUAGES CXX)

set(SRC_FILES
    src/main.cpp
    src/core/App.cpp
    src/core/Display.cpp
    src/core/Mobile.cpp
    src/core/WeatherStation.cpp
    src/utils/Logger.cpp
)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE
    src/include
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    adel
)