SET(INCLUDED_FILES
        ../src/maximumrectangleinhistogram.h 
        ../src/maximumrectangleinhistogram.cpp 
        maximumrectangleinhistogram_test.cpp
    )
add_executable(maximumrectangleinhistogram ${INCLUDED_FILES})
target_link_libraries(maximumrectangleinhistogram gtest gmock_main)
cotire(maximumrectangleinhistogram)
add_test(NAME maximumrectangleinhistogram_test COMMAND maximumrectangleinhistogram)
