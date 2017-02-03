SET(INCLUDED_FILES
        ../src/cardhandmask.h 
        ../src/cardhandmask.cpp 
        cardhandmask_test.cpp
    )
add_executable(cardhandmask ${INCLUDED_FILES})
target_link_libraries(cardhandmask gtest gmock_main)
cotire(cardhandmask)
add_test(NAME cardhandmask_test COMMAND cardhandmask)
