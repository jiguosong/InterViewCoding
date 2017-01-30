SET(INCLUDED_FILES
        ../src/sort_quick.h 
        ../src/sort_quick.cpp 
        sort_quick_test.cpp
    )
add_executable(sort_quick ${INCLUDED_FILES})
target_link_libraries(sort_quick gtest gmock_main)
cotire(sort_quick)
add_test(NAME sort_quick_test COMMAND sort_quick)
