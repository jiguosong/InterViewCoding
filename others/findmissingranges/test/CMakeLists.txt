SET(INCLUDED_FILES
        ../src/findmissingranges.h 
        ../src/findmissingranges.cpp 
        findmissingranges_test.cpp
    )
add_executable(findmissingranges ${INCLUDED_FILES})
target_link_libraries(findmissingranges gtest gmock_main)
cotire(findmissingranges)
add_test(NAME findmissingranges_test COMMAND findmissingranges)
