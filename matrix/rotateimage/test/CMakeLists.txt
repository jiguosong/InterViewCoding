SET(INCLUDED_FILES
        ../src/rotateimage.h 
        ../src/rotateimage.cpp 
        rotateimage_test.cpp
    )
add_executable(rotateimage ${INCLUDED_FILES})
target_link_libraries(rotateimage gtest gmock_main)
cotire(rotateimage)
add_test(NAME rotateimage_test COMMAND rotateimage)
