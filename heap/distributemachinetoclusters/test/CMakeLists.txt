SET(INCLUDED_FILES
        ../src/distributemachinetoclusters.h 
        ../src/distributemachinetoclusters.cpp 
        distributemachinetoclusters_test.cpp
    )
add_executable(distributemachinetoclusters ${INCLUDED_FILES})
target_link_libraries(distributemachinetoclusters gtest gmock_main)
cotire(distributemachinetoclusters)
add_test(NAME distributemachinetoclusters_test COMMAND distributemachinetoclusters)
