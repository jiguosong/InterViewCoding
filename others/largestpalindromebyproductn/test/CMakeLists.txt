SET(INCLUDED_FILES
        ../src/largestpalindromebyproductn.h 
        ../src/largestpalindromebyproductn.cpp 
        largestpalindromebyproductn_test.cpp
    )
add_executable(largestpalindromebyproductn ${INCLUDED_FILES})
target_link_libraries(largestpalindromebyproductn gtest gmock_main)
cotire(largestpalindromebyproductn)
add_test(NAME largestpalindromebyproductn_test COMMAND largestpalindromebyproductn)
