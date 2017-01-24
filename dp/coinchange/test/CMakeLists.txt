SET(INCLUDED_FILES
        ../src/coinchange.h 
        ../src/coinchange.cpp 
        coinchange_test.cpp
    )
add_executable(coinchange ${INCLUDED_FILES})
target_link_libraries(coinchange gtest gmock_main)
cotire(coinchange)
add_test(NAME coinchange_test COMMAND coinchange)
