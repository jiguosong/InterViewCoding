SET(INCLUDED_FILES
        ../src/setmatrixzeros.h 
        ../src/setmatrixzeros.cpp 
        setmatrixzeros_test.cpp
    )
add_executable(setmatrixzeros ${INCLUDED_FILES})
target_link_libraries(setmatrixzeros gtest gmock_main)
cotire(setmatrixzeros)
add_test(NAME setmatrixzeros_test COMMAND setmatrixzeros)
