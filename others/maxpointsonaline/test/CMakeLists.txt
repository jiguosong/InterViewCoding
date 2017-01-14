SET(INCLUDED_FILES
        ../src/maxpointsonaline.h 
        ../src/maxpointsonaline.cpp 
        maxpointsonaline_test.cpp
    )
add_executable(maxpointsonaline ${INCLUDED_FILES})
target_link_libraries(maxpointsonaline gtest gmock_main)
cotire(maxpointsonaline)
add_test(NAME maxpointsonaline_test COMMAND maxpointsonaline)
