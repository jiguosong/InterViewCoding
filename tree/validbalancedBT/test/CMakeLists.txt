SET(INCLUDED_FILES
        ../src/validbalancedBT.h 
        ../src/validbalancedBT.cpp 
        validbalancedBT_test.cpp
    )
add_executable(validbalancedBT ${INCLUDED_FILES})
target_link_libraries(validbalancedBT gtest gmock_main)
cotire(validbalancedBT)
add_test(NAME validbalancedBT_test COMMAND validbalancedBT)
