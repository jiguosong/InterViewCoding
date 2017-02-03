SET(INCLUDED_FILES
        ../src/findmaxwithoutcomparison.h 
        ../src/findmaxwithoutcomparison.cpp 
        findmaxwithoutcomparison_test.cpp
    )
add_executable(findmaxwithoutcomparison ${INCLUDED_FILES})
target_link_libraries(findmaxwithoutcomparison gtest gmock_main)
cotire(findmaxwithoutcomparison)
add_test(NAME findmaxwithoutcomparison_test COMMAND findmaxwithoutcomparison)
