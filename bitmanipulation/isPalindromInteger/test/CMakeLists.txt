SET(INCLUDED_FILES
        ../src/isPalindromInteger.h 
        ../src/isPalindromInteger.cpp 
        isPalindromInteger_test.cpp
    )
add_executable(isPalindromInteger ${INCLUDED_FILES})
target_link_libraries(isPalindromInteger gtest gmock_main)
cotire(isPalindromInteger)
add_test(NAME isPalindromInteger_test COMMAND isPalindromInteger)
