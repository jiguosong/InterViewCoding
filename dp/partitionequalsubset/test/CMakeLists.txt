SET(INCLUDED_FILES
        ../src/partitionequalsubset.h 
        ../src/partitionequalsubset.cpp 
        partitionequalsubset_test.cpp
    )
add_executable(partitionequalsubset ${INCLUDED_FILES})
target_link_libraries(partitionequalsubset gtest gmock_main)
cotire(partitionequalsubset)
add_test(NAME partitionequalsubset_test COMMAND partitionequalsubset)
