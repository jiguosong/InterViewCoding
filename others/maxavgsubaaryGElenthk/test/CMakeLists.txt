SET(INCLUDED_FILES
        ../src/maxavgsubaaryGElenthk.h 
        ../src/maxavgsubaaryGElenthk.cpp 
        maxavgsubaaryGElenthk_test.cpp
    )
add_executable(maxavgsubaaryGElenthk ${INCLUDED_FILES})
target_link_libraries(maxavgsubaaryGElenthk gtest gmock_main)
cotire(maxavgsubaaryGElenthk)
add_test(NAME maxavgsubaaryGElenthk_test COMMAND maxavgsubaaryGElenthk)
