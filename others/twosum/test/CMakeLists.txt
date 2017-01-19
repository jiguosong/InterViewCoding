SET(INCLUDED_FILES
        ../src/twosum.h 
        ../src/twosum.cpp 
        twosum_test.cpp
    )
add_executable(twosum ${INCLUDED_FILES})
target_link_libraries(twosum gtest gmock_main)
cotire(twosum)
add_test(NAME twosum_test COMMAND twosum)
