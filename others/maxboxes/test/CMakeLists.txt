SET(INCLUDED_FILES
        ../src/maxboxes.h 
        ../src/maxboxes.cpp 
        maxboxes_test.cpp
    )
add_executable(maxboxes ${INCLUDED_FILES})
target_link_libraries(maxboxes gtest gmock_main)
cotire(maxboxes)
add_test(NAME maxboxes_test COMMAND maxboxes)
