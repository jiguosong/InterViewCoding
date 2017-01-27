SET(INCLUDED_FILES
        ../src/largestBST.h 
        ../src/largestBST.cpp 
        largestBST_test.cpp
    )
add_executable(largestBST ${INCLUDED_FILES})
target_link_libraries(largestBST gtest gmock_main)
cotire(largestBST)
add_test(NAME largestBST_test COMMAND largestBST)
