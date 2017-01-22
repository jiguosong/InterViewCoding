SET(INCLUDED_FILES
        ../src/findonemissingnum.h 
        ../src/findonemissingnum.cpp 
        findonemissingnum_test.cpp
    )
add_executable(findonemissingnum ${INCLUDED_FILES})
target_link_libraries(findonemissingnum gtest gmock_main)
cotire(findonemissingnum)
add_test(NAME findonemissingnum_test COMMAND findonemissingnum)
