SET(INCLUDED_FILES
        ../src/nearestFibNumber.h 
        ../src/nearestFibNumber.cpp 
        nearestFibNumber_test.cpp
    )
add_executable(nearestFibNumber ${INCLUDED_FILES})
target_link_libraries(nearestFibNumber gtest gmock_main)
cotire(nearestFibNumber)
add_test(NAME nearestFibNumber_test COMMAND nearestFibNumber)
