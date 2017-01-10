SET(INCLUDED_FILES
        ../src/streamingedge.h 
        ../src/streamingedge.cpp 
        streamingedge_test.cpp
    )
add_executable(streamingedge ${INCLUDED_FILES})
target_link_libraries(streamingedge gtest gmock_main)
cotire(streamingedge)
add_test(NAME streamingedge_test COMMAND streamingedge)
