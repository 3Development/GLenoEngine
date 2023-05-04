project(LenoEngine)


include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_GetProperties(googletest)

if (NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR}
            ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

#Define testing
enable_testing()

#COMPILE DEFINITIONS PROPERTIES
add_compile_definitions(ENGINE_PROPERTIES_YAML="/home/leno/DevelopmentCenter/Projects/GameDev/Engines/GLenoEngine/properties/engine_properties.yaml")



add_executable(math_test utilz_tests/math_tests.cpp)
add_executable(shader_test opengl_tests/shader_tests.cpp)


target_link_libraries(
        math_test
        GTest::gtest_main
        lenoEngineProgram
)

target_link_libraries(
        shader_test
        GTest::gtest_main
        lenoEngineProgram
)





include(GoogleTest)
gtest_discover_tests(math_test)
gtest_discover_tests(shader_test)