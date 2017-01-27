SET(INCLUDED_FILES
        ../src/maximumsquareallones.h 
        ../src/maximumsquareallones.cpp 
        maximumsquareallones_test.cpp
    )
add_executable(maximumsquareallones ${INCLUDED_FILES})
target_link_libraries(maximumsquareallones gtest gmock_main)
cotire(maximumsquareallones)
add_test(NAME maximumsquareallones_test COMMAND maximumsquareallones)
