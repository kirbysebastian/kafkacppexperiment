cmake_minimum_required(VERSION 3.15)
project(kafkacppexperiment)

find_package(CppKafka REQUIRED)

add_executable(PRODUCER producer.cpp)
target_link_libraries(PRODUCER CppKafka::cppkafka)

add_executable(CONSUMER consumer.cpp)
target_link_libraries(CONSUMER CppKafka::cppkafka)

