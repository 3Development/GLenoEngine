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



set(TEST_FILES 
    buildproject_test.cpp
        ../include/core/window/window.h)

add_executable(tests ${TEST_FILES})


target_link_libraries(
  tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)