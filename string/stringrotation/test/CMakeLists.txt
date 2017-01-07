SET(INCLUDED_FILES
        ../src/stringrotation.h 
        ../src/stringrotation.cpp 
        stringrotation_test.cpp
    )
add_executable(stringrotation ${INCLUDED_FILES})
target_link_libraries(stringrotation gtest gmock_main)
cotire(stringrotation)
add_test(NAME stringrotation_test COMMAND stringrotation)
