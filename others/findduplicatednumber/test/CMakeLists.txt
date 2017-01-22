SET(INCLUDED_FILES
        ../src/findduplicatednumber.h 
        ../src/findduplicatednumber.cpp 
        findduplicatednumber_test.cpp
    )
add_executable(findduplicatednumber ${INCLUDED_FILES})
target_link_libraries(findduplicatednumber gtest gmock_main)
cotire(findduplicatednumber)
add_test(NAME findduplicatednumber_test COMMAND findduplicatednumber)
