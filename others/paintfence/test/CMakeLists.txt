SET(INCLUDED_FILES
        ../src/paintfence.h 
        ../src/paintfence.cpp 
        paintfence_test.cpp
    )
add_executable(paintfence ${INCLUDED_FILES})
target_link_libraries(paintfence gtest gmock_main)
cotire(paintfence)
add_test(NAME paintfence_test COMMAND paintfence)
