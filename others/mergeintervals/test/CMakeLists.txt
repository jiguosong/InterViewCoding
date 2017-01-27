SET(INCLUDED_FILES
        ../src/mergeintervals.h 
        ../src/mergeintervals.cpp 
        mergeintervals_test.cpp
    )
add_executable(mergeintervals ${INCLUDED_FILES})
target_link_libraries(mergeintervals gtest gmock_main)
cotire(mergeintervals)
add_test(NAME mergeintervals_test COMMAND mergeintervals)
