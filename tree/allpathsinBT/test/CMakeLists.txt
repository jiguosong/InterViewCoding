SET(INCLUDED_FILES
        ../src/allpathsinBT.h 
        ../src/allpathsinBT.cpp 
        allpathsinBT_test.cpp
    )
add_executable(allpathsinBT ${INCLUDED_FILES})
target_link_libraries(allpathsinBT gtest gmock_main)
cotire(allpathsinBT)
add_test(NAME allpathsinBT_test COMMAND allpathsinBT)
