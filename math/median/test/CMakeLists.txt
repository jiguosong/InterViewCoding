SET(INCLUDED_FILES
        ../src/median.h 
        ../src/median.cpp 
        median_test.cpp
    )
add_executable(median ${INCLUDED_FILES})
target_link_libraries(median gtest gmock_main)
cotire(median)
add_test(NAME median_test COMMAND median)
