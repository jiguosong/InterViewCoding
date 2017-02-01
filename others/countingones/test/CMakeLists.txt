SET(INCLUDED_FILES
        ../src/countingones.h 
        ../src/countingones.cpp 
        countingones_test.cpp
    )
add_executable(countingones ${INCLUDED_FILES})
target_link_libraries(countingones gtest gmock_main)
cotire(countingones)
add_test(NAME countingones_test COMMAND countingones)
