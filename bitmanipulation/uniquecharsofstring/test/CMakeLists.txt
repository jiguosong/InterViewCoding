SET(INCLUDED_FILES
        ../src/uniquecharsofstring.h
        ../src/uniquecharsofstring.cpp
        uniquecharsofstring_test.cpp
    )
add_executable(uniquecharsofstring ${INCLUDED_FILES})
target_link_libraries(uniquecharsofstring gtest gmock_main)
cotire(uniquecharsofstring)
add_test(NAME uniquecharsofstring_test COMMAND uniquecharsofstring)
