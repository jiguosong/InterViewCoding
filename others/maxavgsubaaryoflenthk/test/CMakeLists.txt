SET(INCLUDED_FILES
        ../src/maxavgsubaaryoflenthk.h 
        ../src/maxavgsubaaryoflenthk.cpp 
        maxavgsubaaryoflenthk_test.cpp
    )
add_executable(maxavgsubaaryoflenthk ${INCLUDED_FILES})
target_link_libraries(maxavgsubaaryoflenthk gtest gmock_main)
cotire(maxavgsubaaryoflenthk)
add_test(NAME maxavgsubaaryoflenthk_test COMMAND maxavgsubaaryoflenthk)
