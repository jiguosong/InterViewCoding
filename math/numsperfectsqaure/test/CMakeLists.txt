SET(INCLUDED_FILES
        ../src/numsperfectsqaure.h 
        ../src/numsperfectsqaure.cpp 
        numsperfectsqaure_test.cpp
    )
add_executable(numsperfectsqaure ${INCLUDED_FILES})
target_link_libraries(numsperfectsqaure gtest gmock_main)
cotire(numsperfectsqaure)
add_test(NAME numsperfectsqaure_test COMMAND numsperfectsqaure)
