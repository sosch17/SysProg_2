add_library(SymboltableLib 
	src/LinkedList.cpp
	src/StringTab.cpp
	src/Symboltable.cpp
	src/SymTabEntry.cpp)
target_include_directories(SymboltableLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(LinkedListTest src/TestLinkedList.cpp)
target_link_libraries(LinkedListTest LINK_PUBLIC SymboltableLib)

add_executable(StringTabTest src/TestStringTab.cpp)
target_link_libraries(StringTabTest LINK_PUBLIC SymboltableLib)

add_executable(SymboltableTest src/TestSymboltable.cpp)
target_link_libraries(SymboltableTest LINK_PUBLIC SymboltableLib)
