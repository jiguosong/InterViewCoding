SET(INCLUDED_FILES
        ../src/memorylimits.h 
        ../src/memorylimits.cpp 
        memorylimits_test.cpp
    )
add_executable(memorylimits ${INCLUDED_FILES})
target_link_libraries(memorylimits gtest gmock_main)
cotire(memorylimits)
add_test(NAME memorylimits_test COMMAND memorylimits)
