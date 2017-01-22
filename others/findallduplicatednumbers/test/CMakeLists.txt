SET(INCLUDED_FILES
        ../src/findallduplicatednumbers.h
        ../src/findallduplicatednumbers.cpp
        findallduplicatednumbers_test.cpp
    )
add_executable(findallduplicatednumbers ${INCLUDED_FILES})
target_link_libraries(findallduplicatednumbers gtest gmock_main)
cotire(findallduplicatednumbers)
add_test(NAME findallduplicatednumbers_test COMMAND findallduplicatednumbers)
