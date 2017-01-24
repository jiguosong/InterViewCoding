SET(INCLUDED_FILES
        ../src/powerxn.h 
        ../src/powerxn.cpp 
        powerxn_test.cpp
    )
add_executable(powerxn ${INCLUDED_FILES})
target_link_libraries(powerxn gtest gmock_main)
cotire(powerxn)
add_test(NAME powerxn_test COMMAND powerxn)
