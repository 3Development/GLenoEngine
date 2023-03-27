project(LenoEngine)

add_executable(maintest maintest.cpp)

target_link_libraries(maintest
        PRIVATE
        core)

