SET(ROCKSDB_HOME /opt/rocksdb)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(test)

ADD_EXECUTABLE(test test.cpp)
INCLUDE_DIRECTORIES(
    ${ROCKSDB_HOME}/include
    /usr/local/opt/zlib/include
)
TARGET_LINK_LIBRARIES(test ${ROCKSDB_HOME}/librocksdb.a snappy z bz2)

ADD_DEFINITIONS(-Wall -std=c++11 -g -O2 -DZLIB)
