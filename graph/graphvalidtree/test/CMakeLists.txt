SET(INCLUDED_FILES
        ../src/graphvalidtree.h 
        ../src/graphvalidtree.cpp 
        graphvalidtree_test.cpp
    )
add_executable(graphvalidtree ${INCLUDED_FILES})
target_link_libraries(graphvalidtree gtest gmock_main)
cotire(graphvalidtree)
add_test(NAME graphvalidtree_test COMMAND graphvalidtree)
