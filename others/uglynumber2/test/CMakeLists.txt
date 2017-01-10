SET(INCLUDED_FILES
        ../src/uglynumber2.h 
        ../src/uglynumber2.cpp 
        uglynumber2_test.cpp
    )
add_executable(uglynumber2 ${INCLUDED_FILES})
target_link_libraries(uglynumber2 gtest gmock_main)
cotire(uglynumber2)
add_test(NAME uglynumber2_test COMMAND uglynumber2)
