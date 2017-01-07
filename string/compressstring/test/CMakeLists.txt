SET(INCLUDED_FILES
        ../src/compressstring.h 
        ../src/compressstring.cpp 
        compressstring_test.cpp
    )
add_executable(compressstring ${INCLUDED_FILES})
target_link_libraries(compressstring gtest gmock_main)
cotire(compressstring)
add_test(NAME compressstring_test COMMAND compressstring)
