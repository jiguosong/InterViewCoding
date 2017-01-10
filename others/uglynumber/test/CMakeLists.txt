SET(INCLUDED_FILES
        ../src/uglynumber.h 
        ../src/uglynumber.cpp 
        uglynumber_test.cpp
    )
add_executable(uglynumber ${INCLUDED_FILES})
target_link_libraries(uglynumber gtest gmock_main)
cotire(uglynumber)
add_test(NAME uglynumber_test COMMAND uglynumber)
