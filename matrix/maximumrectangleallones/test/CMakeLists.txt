SET(INCLUDED_FILES
        ../src/maximumrectangleallones.h 
        ../src/maximumrectangleallones.cpp 
        maximumrectangleallones_test.cpp
    )
add_executable(maximumrectangleallones ${INCLUDED_FILES})
target_link_libraries(maximumrectangleallones gtest gmock_main)
cotire(maximumrectangleallones)
add_test(NAME maximumrectangleallones_test COMMAND maximumrectangleallones)
