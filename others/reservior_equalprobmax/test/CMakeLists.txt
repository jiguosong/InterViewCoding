SET(INCLUDED_FILES
        ../src/reservior_equalprobmax.h 
        ../src/reservior_equalprobmax.cpp 
        reservior_equalprobmax_test.cpp
    )
add_executable(reservior_equalprobmax ${INCLUDED_FILES})
target_link_libraries(reservior_equalprobmax gtest gmock_main)
cotire(reservior_equalprobmax)
add_test(NAME reservior_equalprobmax_test COMMAND reservior_equalprobmax)
