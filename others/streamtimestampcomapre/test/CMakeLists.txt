SET(INCLUDED_FILES
        ../src/streamtimestampcomapre.h 
        ../src/streamtimestampcomapre.cpp 
        streamtimestampcomapre_test.cpp
    )
add_executable(streamtimestampcomapre ${INCLUDED_FILES})
target_link_libraries(streamtimestampcomapre gtest gmock_main)
cotire(streamtimestampcomapre)
add_test(NAME streamtimestampcomapre_test COMMAND streamtimestampcomapre)
