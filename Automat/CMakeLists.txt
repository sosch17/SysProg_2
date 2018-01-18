add_library(AutomatLib src/Automat.cpp)
target_include_directories(AutomatLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(AutomatTest src/TestAutomat.cpp)
target_link_libraries(AutomatTest LINK_PUBLIC AutomatLib )
