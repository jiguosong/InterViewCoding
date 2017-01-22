SET(INCLUDED_FILES
        ../src/findallmissingnumbers.h
        ../src/findallmissingnumbers.cpp
        findallmissingnumbers_test.cpp
    )
add_executable(findallmissingnumbers ${INCLUDED_FILES})
target_link_libraries(findallmissingnumbers gtest gmock_main)
cotire(findallmissingnumbers)
add_test(NAME findallmissingnumbers_test COMMAND findallmissingnumbers)
