SET(INCLUDED_FILES
        ../src/myatoi.h 
        ../src/myatoi.cpp 
        myatoi_test.cpp
    )
add_executable(myatoi ${INCLUDED_FILES})
target_link_libraries(myatoi gtest gmock_main)
cotire(myatoi)
add_test(NAME myatoi_test COMMAND myatoi)
