SET(INCLUDED_FILES
        ../src/longestincreasingsubsequence.h 
        ../src/longestincreasingsubsequence.cpp 
        longestincreasingsubsequence_test.cpp
    )
add_executable(longestincreasingsubsequence ${INCLUDED_FILES})
target_link_libraries(longestincreasingsubsequence gtest gmock_main)
cotire(longestincreasingsubsequence)
add_test(NAME longestincreasingsubsequence_test COMMAND longestincreasingsubsequence)
