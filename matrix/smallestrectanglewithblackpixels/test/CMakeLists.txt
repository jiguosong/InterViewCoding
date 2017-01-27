SET(INCLUDED_FILES
        ../src/smallestrectanglewithblackpixels.h 
        ../src/smallestrectanglewithblackpixels.cpp 
        smallestrectanglewithblackpixels_test.cpp
    )
add_executable(smallestrectanglewithblackpixels ${INCLUDED_FILES})
target_link_libraries(smallestrectanglewithblackpixels gtest gmock_main)
cotire(smallestrectanglewithblackpixels)
add_test(NAME smallestrectanglewithblackpixels_test COMMAND smallestrectanglewithblackpixels)
