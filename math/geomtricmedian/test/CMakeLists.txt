SET(INCLUDED_FILES
        ../src/geomtricmedian.h 
        ../src/geomtricmedian.cpp 
        geomtricmedian_test.cpp
    )
add_executable(geomtricmedian ${INCLUDED_FILES})
target_link_libraries(geomtricmedian gtest gmock_main)
cotire(geomtricmedian)
add_test(NAME geomtricmedian_test COMMAND geomtricmedian)
