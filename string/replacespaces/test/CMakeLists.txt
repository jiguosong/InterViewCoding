SET(INCLUDED_FILES
        ../src/replacespaces.h 
        ../src/replacespaces.cpp 
        replacespaces_test.cpp
    )
add_executable(replacespaces ${INCLUDED_FILES})
target_link_libraries(replacespaces gtest gmock_main)
cotire(replacespaces)
add_test(NAME replacespaces_test COMMAND replacespaces)
