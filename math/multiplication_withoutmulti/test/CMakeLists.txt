SET(INCLUDED_FILES
        ../src/multiplication_withoutmulti.h 
        ../src/multiplication_withoutmulti.cpp 
        multiplication_withoutmulti_test.cpp
    )
add_executable(multiplication_withoutmulti ${INCLUDED_FILES})
target_link_libraries(multiplication_withoutmulti gtest gmock_main)
cotire(multiplication_withoutmulti)
add_test(NAME multiplication_withoutmulti_test COMMAND multiplication_withoutmulti)
