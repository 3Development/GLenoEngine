cmake_minimum_required(VERSION 3.24)
project(LenoEngine LANGUAGES CXX)


add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(tests)




#Functions --------------------------------

function (printVar)
    
    foreach( var ${ARGN})
        message("${var} = ${${var}}")
    endforeach()
    
endfunction()


printVar(PROJECT_NAME)