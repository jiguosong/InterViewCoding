SET(INCLUDED_FILES
        ../src/uniqestrings.h 
        ../src/uniqestrings.cpp 
        uniqestrings_test.cpp
    )
add_executable(uniqestrings ${INCLUDED_FILES})
target_link_libraries(uniqestrings gtest gmock_main)
cotire(uniqestrings)
add_test(NAME uniqestrings_test COMMAND uniqestrings)
