SET(INCLUDED_FILES
        ../src/simplemalloc.h 
        ../src/simplemalloc.cpp 
        simplemalloc_test.cpp
    )
add_executable(simplemalloc ${INCLUDED_FILES})
target_link_libraries(simplemalloc gtest gmock_main)
cotire(simplemalloc)
add_test(NAME simplemalloc_test COMMAND simplemalloc)
