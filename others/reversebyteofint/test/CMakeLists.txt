SET(INCLUDED_FILES
        ../src/reversebyteofint.h 
        ../src/reversebyteofint.cpp 
        reversebyteofint_test.cpp
    )
add_executable(reversebyteofint ${INCLUDED_FILES})
target_link_libraries(reversebyteofint gtest gmock_main)
cotire(reversebyteofint)
add_test(NAME reversebyteofint_test COMMAND reversebyteofint)
