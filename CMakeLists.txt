cmake_minimum_required(VERSION 3.19)
project(TwoApplicationsExchange)

set(CMAKE_CXX_STANDARD 11)

add_executable(TwoApplicationsExchangeA applicationA.cpp)
add_executable(TwoApplicationsExchangeB applicationB.cpp)