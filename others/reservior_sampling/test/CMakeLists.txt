SET(INCLUDED_FILES
        ../src/reservior_sampling.h 
        ../src/reservior_sampling.cpp 
        reservior_sampling_test.cpp
    )
add_executable(reservior_sampling ${INCLUDED_FILES})
target_link_libraries(reservior_sampling gtest gmock_main)
cotire(reservior_sampling)
add_test(NAME reservior_sampling_test COMMAND reservior_sampling)
