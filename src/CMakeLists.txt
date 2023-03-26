project(LenoEngine)

add_executable(test main.cpp)


find_package(X11 REQUIRED)

if(X11_FOUND)
    message("X11 Found")
    include_directories(${X11_INCLUDE_DIRS})
    link_libraries (${X11_LIBRARIES})
    target_link_libraries(test X11)
endif(X11_FOUND)


# OpenGL
find_package(OpenGL REQUIRED)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/glfw-3.3.8/" "${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/glfw-3.3.8/build" EXCLUDE_FROM_ALL)
target_link_libraries(test glfw)


add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/glew-2.2.0/build/cmake" "${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/glew-2.2.0/build/" EXCLUDE_FROM_ALL)
target_include_directories(test PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/glew-2.2.0/include
)

#find_package(glfw3 REQUIRED)
#if (glfw3_FOUND)
#  message (STATUS ${CMAKE_CURRENT_SOURCE_DIR})
#  message(STATUS "Found GLFW3 in ${glfw3_INCLUDE_DIR}")
#  include_directories(${glfw3_INCLUDE_DIRS})
#  link_libraries (${glfw3_LIBRARIES})
#  target_link_libraries(test glfw3)
#endif (glfw3_FOUND)


#find_package(GLEW REQUIRED)
#if (GLEW_FOUND)
#  message(STATUS "Glew found")
#  include_directories(${GLEW_INCLUDE_DIRS})
#  link_libraries (${GLEW_LIBRARIES})
#endif (GLEW_FOUND)