SET(INCLUDED_FILES
        ../src/endianess.h 
        ../src/endianess.cpp 
        endianess_test.cpp
    )
add_executable(endianess ${INCLUDED_FILES})
target_link_libraries(endianess gtest gmock_main)
cotire(endianess)
add_test(NAME endianess_test COMMAND endianess)
