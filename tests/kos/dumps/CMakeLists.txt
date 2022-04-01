cmake_minimum_required(VERSION 3.2)

add_subdirectory(network/libevent-2.1.12-stable)

add_executable(dump_proxy proxy.cpp network/KOSProxyServer.cpp file/KOSDumpWriter.cpp)

target_include_directories(dump_proxy PRIVATE network/libevent-2.1.12-stable/include ./)
target_link_libraries(dump_proxy event)
