SET(INCLUDED_FILES
        ../src/buildtreefromsortedarray.h 
        ../src/buildtreefromsortedarray.cpp 
        buildtreefromsortedarray_test.cpp
    )
add_executable(buildtreefromsortedarray ${INCLUDED_FILES})
target_link_libraries(buildtreefromsortedarray gtest gmock_main)
cotire(buildtreefromsortedarray)
add_test(NAME buildtreefromsortedarray_test COMMAND buildtreefromsortedarray)
