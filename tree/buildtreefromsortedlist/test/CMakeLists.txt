SET(INCLUDED_FILES
        ../src/buildtreefromsortedlist.h 
        ../src/buildtreefromsortedlist.cpp 
        buildtreefromsortedlist_test.cpp
    )
add_executable(buildtreefromsortedlist ${INCLUDED_FILES})
target_link_libraries(buildtreefromsortedlist gtest gmock_main)
cotire(buildtreefromsortedlist)
add_test(NAME buildtreefromsortedlist_test COMMAND buildtreefromsortedlist)
