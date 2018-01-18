add_library(ScannerLib src/Scanner.cpp src/OutputBuffer.cpp)
target_include_directories(ScannerLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(ScannerTest src/TestScanner.cpp)
target_link_libraries(ScannerTest LINK_PUBLIC 
ScannerLib 
TokenLib 
AutomatLib 
BufferLib 
SymboltableLib)

add_executable(OutputBufferTest src/TestOutputBuffer.cpp)
target_link_libraries(OutputBufferTest LINK_PUBLIC 
ScannerLib 
TokenLib 
AutomatLib 
BufferLib
SymboltableLib)
