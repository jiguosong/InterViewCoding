SET(INCLUDED_FILES
        ../src/majoritynumber2.h 
        ../src/majoritynumber2.cpp 
        majoritynumber2_test.cpp
    )
add_executable(majoritynumber2 ${INCLUDED_FILES})
target_link_libraries(majoritynumber2 gtest gmock_main)
cotire(majoritynumber2)
add_test(NAME majoritynumber2_test COMMAND majoritynumber2)
