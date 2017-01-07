SET(INCLUDED_FILES
        ../src/onesandzeros.h 
        ../src/onesandzeros.cpp 
        onesandzeros_test.cpp
    )
add_executable(onesandzeros ${INCLUDED_FILES})
target_link_libraries(onesandzeros gtest gmock_main)
cotire(onesandzeros)
add_test(NAME onesandzeros_test COMMAND onesandzeros)
