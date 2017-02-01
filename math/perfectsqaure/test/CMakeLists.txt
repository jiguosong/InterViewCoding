SET(INCLUDED_FILES
        ../src/perfectsqaure.h 
        ../src/perfectsqaure.cpp 
        perfectsqaure_test.cpp
    )
add_executable(perfectsqaure ${INCLUDED_FILES})
target_link_libraries(perfectsqaure gtest gmock_main)
cotire(perfectsqaure)
add_test(NAME perfectsqaure_test COMMAND perfectsqaure)
