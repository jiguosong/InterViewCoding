SET(INCLUDED_FILES
        ../src/perfectrectangle.h 
        ../src/perfectrectangle.cpp 
        perfectrectangle_test.cpp
    )
add_executable(perfectrectangle ${INCLUDED_FILES})
target_link_libraries(perfectrectangle gtest gmock_main)
cotire(perfectrectangle)
add_test(NAME perfectrectangle_test COMMAND perfectrectangle)
