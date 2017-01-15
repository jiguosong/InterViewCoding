SET(INCLUDED_FILES
        ../src/majoritynumber.h 
        ../src/majoritynumber.cpp 
        majoritynumber_test.cpp
    )
add_executable(majoritynumber ${INCLUDED_FILES})
target_link_libraries(majoritynumber gtest gmock_main)
cotire(majoritynumber)
add_test(NAME majoritynumber_test COMMAND majoritynumber)
