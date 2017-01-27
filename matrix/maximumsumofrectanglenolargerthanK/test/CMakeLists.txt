SET(INCLUDED_FILES
        ../src/maximumsumofrectanglenolargerthanK.h 
        ../src/maximumsumofrectanglenolargerthanK.cpp 
        maximumsumofrectanglenolargerthanK_test.cpp
    )
add_executable(maximumsumofrectanglenolargerthanK ${INCLUDED_FILES})
target_link_libraries(maximumsumofrectanglenolargerthanK gtest gmock_main)
cotire(maximumsumofrectanglenolargerthanK)
add_test(NAME maximumsumofrectanglenolargerthanK_test COMMAND maximumsumofrectanglenolargerthanK)
