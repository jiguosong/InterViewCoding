SET(INCLUDED_FILES
        ../src/sortlist.h 
        ../src/sortlist.cpp 
        sortlist_test.cpp
    )
add_executable(sortlist ${INCLUDED_FILES})
target_link_libraries(sortlist gtest gmock_main)
cotire(sortlist)
add_test(NAME sortlist_test COMMAND sortlist)
