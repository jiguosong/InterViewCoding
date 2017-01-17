SET(INCLUDED_FILES
        ../src/maxdepthBT.h 
        ../src/maxdepthBT.cpp 
        maxdepthBT_test.cpp
    )
add_executable(maxdepthBT ${INCLUDED_FILES})
target_link_libraries(maxdepthBT gtest gmock_main)
cotire(maxdepthBT)
add_test(NAME maxdepthBT_test COMMAND maxdepthBT)
