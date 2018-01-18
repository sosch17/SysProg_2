add_library(ParserLib src/ParseTree.cpp src/TypeCheck.cpp)
target_include_directories(ParserLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(ParserTest src/TestParseTree.cpp)
target_link_libraries(ParserTest LINK_PUBLIC ParserLib ScannerLib AutomatLib  SymboltableLib  TokenLib   BufferLib)
