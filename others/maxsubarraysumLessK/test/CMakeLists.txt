SET(INCLUDED_FILES
        ../src/maxsubarraysumLessK.h 
        ../src/maxsubarraysumLessK.cpp 
        maxsubarraysumLessK_test.cpp
    )
add_executable(maxsubarraysumLessK ${INCLUDED_FILES})
target_link_libraries(maxsubarraysumLessK gtest gmock_main)
cotire(maxsubarraysumLessK)
add_test(NAME maxsubarraysumLessK_test COMMAND maxsubarraysumLessK)
