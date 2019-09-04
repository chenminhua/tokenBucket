cmake_minimum_required(VERSION 3.7)
project(tokenBucket)


############################################################
# Create a library
############################################################
add_library(tokenBucket STATIC src/tokenBucket.cpp)

target_include_directories(tokenBucket PUBLIC ${PROJECT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 11)


############################################################
# Create an executable
############################################################

# Add an executable with the above sources
add_executable(hello_tb
        src/main.cpp
        )

# link the new hello_library target with the hello_binary target
target_link_libraries( hello_tb
        PRIVATE
        tokenBucket
        )