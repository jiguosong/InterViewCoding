SET(INCLUDED_FILES
        ../src/reverseinteger.h 
        ../src/reverseinteger.cpp 
        reverseinteger_test.cpp
    )
add_executable(reverseinteger ${INCLUDED_FILES})
target_link_libraries(reverseinteger gtest gmock_main)
cotire(reverseinteger)
add_test(NAME reverseinteger_test COMMAND reverseinteger)
