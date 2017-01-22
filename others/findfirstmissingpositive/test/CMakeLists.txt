SET(INCLUDED_FILES
        ../src/findfirstmissingpositive.h 
        ../src/findfirstmissingpositive.cpp 
        findfirstmissingpositive_test.cpp
    )
add_executable(findfirstmissingpositive ${INCLUDED_FILES})
target_link_libraries(findfirstmissingpositive gtest gmock_main)
cotire(findfirstmissingpositive)
add_test(NAME findfirstmissingpositive_test COMMAND findfirstmissingpositive)
