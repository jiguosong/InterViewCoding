SET(INCLUDED_FILES
        ../src/removeduplicatedletters.h 
        ../src/removeduplicatedletters.cpp 
        removeduplicatedletters_test.cpp
    )
add_executable(removeduplicatedletters ${INCLUDED_FILES})
target_link_libraries(removeduplicatedletters gtest gmock_main)
cotire(removeduplicatedletters)
add_test(NAME removeduplicatedletters_test COMMAND removeduplicatedletters)
