SET(INCLUDED_FILES
        ../src/constructbstfrompreorder.h 
        ../src/constructbstfrompreorder.cpp 
        constructbstfrompreorder_test.cpp
    )
add_executable(constructbstfrompreorder ${INCLUDED_FILES})
target_link_libraries(constructbstfrompreorder gtest gmock_main)
cotire(constructbstfrompreorder)
add_test(NAME constructbstfrompreorder_test COMMAND constructbstfrompreorder)
