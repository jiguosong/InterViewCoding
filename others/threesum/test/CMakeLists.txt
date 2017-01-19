SET(INCLUDED_FILES
        ../src/threesum.h 
        ../src/threesum.cpp 
        threesum_test.cpp
    )
add_executable(threesum ${INCLUDED_FILES})
target_link_libraries(threesum gtest gmock_main)
cotire(threesum)
add_test(NAME threesum_test COMMAND threesum)
