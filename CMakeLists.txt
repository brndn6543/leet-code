cmake_minimum_required(VERSION 3.31)

# Enable both C and C++.
project(leet-code LANGUAGES C CXX)

# Use C11.
set(CMAKE_C_STANDARD            11)
set(CMAKE_C_STANDARD_REQUIRED   ON)

# Use C++20.
set(CMAKE_CXX_STANDARD          20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(leet_code src/c/main.c)
add_executable(two_sum src/c/two_sum.c)
add_executable(playground test/playground.c)
add_executable(add_two_numbers src/cpp/add_two_numbers.cpp)
add_executable(longest_substring_no_repeats src/cpp/longest_substring_no_repeats.cpp)