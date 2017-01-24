SET(INCLUDED_FILES
        ../src/hashtable_chaining.h 
        ../src/hashtable_chaining.cpp 
        hashtable_chaining_test.cpp
    )
add_executable(hashtable_chaining ${INCLUDED_FILES})
target_link_libraries(hashtable_chaining gtest gmock_main)
cotire(hashtable_chaining)
add_test(NAME hashtable_chaining_test COMMAND hashtable_chaining)
