SET(INCLUDED_FILES
        ../src/swaptwonodes.h 
        ../src/swaptwonodes.cpp 
        swaptwonodes_test.cpp
    )
add_executable(swaptwonodes ${INCLUDED_FILES})
target_link_libraries(swaptwonodes gtest gmock_main)
cotire(swaptwonodes)
add_test(NAME swaptwonodes_test COMMAND swaptwonodes)
