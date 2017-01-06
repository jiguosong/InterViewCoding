SET(INCLUDED_FILES
        ../src/jumpgame.h 
        ../src/jumpgame.cpp 
        jumpgame_test.cpp
    )
add_executable(jumpgame ${INCLUDED_FILES})
target_link_libraries(jumpgame gtest gmock_main)
cotire(jumpgame)
add_test(NAME jumpgame_test COMMAND jumpgame)
