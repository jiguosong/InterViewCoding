SET(INCLUDED_FILES
        ../src/longestcommonincreasingsubsequence.h 
        ../src/longestcommonincreasingsubsequence.cpp 
        longestcommonincreasingsubsequence_test.cpp
    )
add_executable(longestcommonincreasingsubsequence ${INCLUDED_FILES})
target_link_libraries(longestcommonincreasingsubsequence gtest gmock_main)
cotire(longestcommonincreasingsubsequence)
add_test(NAME longestcommonincreasingsubsequence_test COMMAND longestcommonincreasingsubsequence)
