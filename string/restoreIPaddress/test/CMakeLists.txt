SET(INCLUDED_FILES
        ../src/restoreIPaddress.h 
        ../src/restoreIPaddress.cpp 
        restoreIPaddress_test.cpp
    )
add_executable(restoreIPaddress ${INCLUDED_FILES})
target_link_libraries(restoreIPaddress gtest gmock_main)
cotire(restoreIPaddress)
add_test(NAME restoreIPaddress_test COMMAND restoreIPaddress)
