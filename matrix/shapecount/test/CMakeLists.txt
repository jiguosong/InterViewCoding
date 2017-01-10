SET(INCLUDED_FILES
        ../src/shapecount.h 
        ../src/shapecount.cpp 
        shapecount_test.cpp
    )
add_executable(shapecount ${INCLUDED_FILES})
target_link_libraries(shapecount gtest gmock_main)
cotire(shapecount)
add_test(NAME shapecount_test COMMAND shapecount)
