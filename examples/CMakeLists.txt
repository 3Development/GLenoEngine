project(LenoEngine)

add_executable(maintest openglLearn.cpp)
add_executable(maintest1 modernOpenglLearn.cpp)

add_executable(cpptest cppPractice.cpp)

target_link_libraries(maintest1
        PRIVATE
        core)


target_link_libraries(maintest
        PRIVATE
        core)

target_link_libraries(cpptest
        PRIVATE
        core)


