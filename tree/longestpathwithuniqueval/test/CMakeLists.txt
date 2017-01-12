SET(INCLUDED_FILES
        ../src/longestpathwithuniqueval.h 
        ../src/longestpathwithuniqueval.cpp 
        longestpathwithuniqueval_test.cpp
    )
add_executable(longestpathwithuniqueval ${INCLUDED_FILES})
target_link_libraries(longestpathwithuniqueval gtest gmock_main)
cotire(longestpathwithuniqueval)
add_test(NAME longestpathwithuniqueval_test COMMAND longestpathwithuniqueval)
