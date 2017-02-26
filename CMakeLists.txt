cmake_minimum_required(VERSION 3.6)
project(amq-c-sample)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES_C consumer.cpp)
set(SOURCE_FILES_P producer.cpp)

include_directories(/usr/local/include/activemq-cpp-3.9.3 /usr/include/apr-1/)

add_executable(amqCppTestConsumer ${SOURCE_FILES_C})

add_executable(amqCppTestProducer ${SOURCE_FILES_P})


target_link_libraries(amqCppTestConsumer /usr/local/lib/libactivemq-cpp.19.dylib)
target_link_libraries(amqCppTestProducer /usr/local/lib/libactivemq-cpp.19.dylib)