SET(INCLUDED_FILES
        ../src/rotatelist.h 
        ../src/rotatelist.cpp 
        rotatelist_test.cpp
    )
add_executable(rotatelist ${INCLUDED_FILES})
target_link_libraries(rotatelist gtest gmock_main)
cotire(rotatelist)
add_test(NAME rotatelist_test COMMAND rotatelist)
