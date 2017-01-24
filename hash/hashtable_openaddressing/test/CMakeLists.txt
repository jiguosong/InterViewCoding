SET(INCLUDED_FILES
        ../src/hashtable_openaddressing.h 
        ../src/hashtable_openaddressing.cpp 
        hashtable_openaddressing_test.cpp
    )
add_executable(hashtable_openaddressing ${INCLUDED_FILES})
target_link_libraries(hashtable_openaddressing gtest gmock_main)
cotire(hashtable_openaddressing)
add_test(NAME hashtable_openaddressing_test COMMAND hashtable_openaddressing)
