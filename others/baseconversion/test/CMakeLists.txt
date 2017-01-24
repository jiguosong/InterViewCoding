SET(INCLUDED_FILES
        ../src/baseconversion.h 
        ../src/baseconversion.cpp 
        baseconversion_test.cpp
    )
add_executable(baseconversion ${INCLUDED_FILES})
target_link_libraries(baseconversion gtest gmock_main)
cotire(baseconversion)
add_test(NAME baseconversion_test COMMAND baseconversion)
