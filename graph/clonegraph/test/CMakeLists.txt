SET(INCLUDED_FILES
        ../src/clonegraph.h 
        ../src/clonegraph.cpp 
        clonegraph_test.cpp
    )
add_executable(clonegraph ${INCLUDED_FILES})
target_link_libraries(clonegraph gtest gmock_main)
cotire(clonegraph)
add_test(NAME clonegraph_test COMMAND clonegraph)
