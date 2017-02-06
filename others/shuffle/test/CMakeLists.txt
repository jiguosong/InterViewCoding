SET(INCLUDED_FILES
        ../src/shuffle.h 
        ../src/shuffle.cpp 
        shuffle_test.cpp
    )
add_executable(shuffle ${INCLUDED_FILES})
target_link_libraries(shuffle gtest gmock_main)
cotire(shuffle)
add_test(NAME shuffle_test COMMAND shuffle)
