SET(INCLUDED_FILES
        ../src/readlastklines.h 
        ../src/readlastklines.cpp 
        readlastklines_test.cpp
    )
add_executable(readlastklines ${INCLUDED_FILES})
target_link_libraries(readlastklines gtest gmock_main)
cotire(readlastklines)
add_test(NAME readlastklines_test COMMAND readlastklines)
