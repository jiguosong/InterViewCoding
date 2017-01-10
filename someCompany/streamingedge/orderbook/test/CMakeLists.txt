SET(INCLUDED_FILES
        ../src/orderbook.h 
        ../src/orderbook.cpp 
        orderbook_test.cpp
    )
add_executable(orderbook ${INCLUDED_FILES})
target_link_libraries(orderbook gtest gmock_main)
cotire(orderbook)
add_test(NAME orderbook_test COMMAND orderbook)
