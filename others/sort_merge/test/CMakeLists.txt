SET(INCLUDED_FILES
        ../src/sort_merge.h 
        ../src/sort_merge.cpp 
        sort_merge_test.cpp
    )
add_executable(sort_merge ${INCLUDED_FILES})
target_link_libraries(sort_merge gtest gmock_main)
cotire(sort_merge)
add_test(NAME sort_merge_test COMMAND sort_merge)
