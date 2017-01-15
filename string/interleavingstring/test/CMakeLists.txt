SET(INCLUDED_FILES
        ../src/interleavingstring.h 
        ../src/interleavingstring.cpp 
        interleavingstring_test.cpp
    )
add_executable(interleavingstring ${INCLUDED_FILES})
target_link_libraries(interleavingstring gtest gmock_main)
cotire(interleavingstring)
add_test(NAME interleavingstring_test COMMAND interleavingstring)
