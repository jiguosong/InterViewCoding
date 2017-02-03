SET(INCLUDED_FILES
        ../src/hammingdistance.h 
        ../src/hammingdistance.cpp 
        hammingdistance_test.cpp
    )
add_executable(hammingdistance ${INCLUDED_FILES})
target_link_libraries(hammingdistance gtest gmock_main)
cotire(hammingdistance)
add_test(NAME hammingdistance_test COMMAND hammingdistance)
