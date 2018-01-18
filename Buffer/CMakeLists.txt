add_library(BufferLib src/Buffer.cpp)
target_include_directories(BufferLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(BufferTest src/TestBuffer.cpp)
target_link_libraries(BufferTest LINK_PUBLIC BufferLib )
