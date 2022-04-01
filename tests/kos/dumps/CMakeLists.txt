cmake_minimum_required(VERSION 3.2)

add_subdirectory(network/libevent-2.1.12-stable)

add_executable(dump_proxy proxy.cpp network/KOSProxyServer.cpp file/KOSDumpWriter.cpp)
target_include_directories(dump_proxy PRIVATE network/libevent-2.1.12-stable/include ./)
target_link_libraries(dump_proxy event)

add_executable(dump_client client.cpp network/KOSClient.cpp file/KOSSMBDumpReader.cpp)
target_include_directories(dump_client PRIVATE network/libevent-2.1.12-stable/include ./)
target_link_libraries(dump_client event)
