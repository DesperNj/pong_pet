cmake_minimum_required(VERSION 2.20)
project(Pong LANGUAGES C CXX)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

file(GLOB_RECURSE SOURCES
    src/*.h
    src/*.cpp
)

add_executable(${PROJECT_NAME}  ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC libs/include)
target_include_directories(${PROJECT_NAME} PUBLIC src/Application)
target_include_directories(${PROJECT_NAME} PUBLIC src/Core)
target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/libs/SFML/*.lib)

file(MAKE_DIRECTORY Build/Debug)
file(GLOB DLLs
    "libs/SFML/bin/*.dll"
)

file(GLOB RESOURCES
    "resources/*"
)

file(COPY ${DLLs} DESTINATION ${PROJECT_SOURCE_DIR}/Build/Debug)
file(COPY ${RESOURCES} DESTINATION ${PROJECT_SOURCE_DIR}/Build)
file(COPY ${RESOURCES} DESTINATION ${PROJECT_SOURCE_DIR}/Build/Debug)
