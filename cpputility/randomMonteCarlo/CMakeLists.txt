add_executable(randomMonteCarlo multithreadMonteCarlo.cpp)
set_target_properties(randomMonteCarlo PROPERTIES COMPILE_FLAGS -pthread LINK_FLAGS -pthread)