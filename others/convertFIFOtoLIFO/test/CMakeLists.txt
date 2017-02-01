SET(INCLUDED_FILES
        ../src/convertFIFOtoLIFO.h 
        ../src/convertFIFOtoLIFO.cpp 
        convertFIFOtoLIFO_test.cpp
    )
add_executable(convertFIFOtoLIFO ${INCLUDED_FILES})
target_link_libraries(convertFIFOtoLIFO gtest gmock_main)
cotire(convertFIFOtoLIFO)
add_test(NAME convertFIFOtoLIFO_test COMMAND convertFIFOtoLIFO)
