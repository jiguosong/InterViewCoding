SET(INCLUDED_FILES
        ../src/pointintriangle.h 
        ../src/pointintriangle.cpp 
        pointintriangle_test.cpp
    )
add_executable(pointintriangle ${INCLUDED_FILES})
target_link_libraries(pointintriangle gtest gmock_main)
cotire(pointintriangle)
add_test(NAME pointintriangle_test COMMAND pointintriangle)
