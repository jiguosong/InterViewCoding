SET(INCLUDED_FILES
        ../src/kcomplimentarypairs.h 
        ../src/kcomplimentarypairs.cpp 
        kcomplimentarypairs_test.cpp
    )
add_executable(kcomplimentarypairs ${INCLUDED_FILES})
target_link_libraries(kcomplimentarypairs gtest gmock_main)
cotire(kcomplimentarypairs)
add_test(NAME kcomplimentarypairs_test COMMAND kcomplimentarypairs)
