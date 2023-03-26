project(LenoEngine)

add_library(maintest maintest.cpp)

target_link_libraries(maintest 
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)