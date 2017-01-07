SET(INCLUDED_FILES
        ../src/partitionlist.h 
        ../src/partitionlist.cpp 
        partitionlist_test.cpp
    )
add_executable(partitionlist ${INCLUDED_FILES})
target_link_libraries(partitionlist gtest gmock_main)
cotire(partitionlist)
add_test(NAME partitionlist_test COMMAND partitionlist)
