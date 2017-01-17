SET(INCLUDED_FILES
        ../src/mindepthBT.h 
        ../src/mindepthBT.cpp 
        mindepthBT_test.cpp
    )
add_executable(mindepthBT ${INCLUDED_FILES})
target_link_libraries(mindepthBT gtest gmock_main)
cotire(mindepthBT)
add_test(NAME mindepthBT_test COMMAND mindepthBT)
