SET(INCLUDED_FILES
        ../src/lrucache.h 
        ../src/lrucache.cpp 
        lrucache_test.cpp
    )
add_executable(lrucache ${INCLUDED_FILES})
target_link_libraries(lrucache gtest gmock_main)
cotire(lrucache)
add_test(NAME lrucache_test COMMAND lrucache)
