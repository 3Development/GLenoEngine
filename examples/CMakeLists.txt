project(LenoEngine)

add_executable(maintest openglLearn.cpp)
add_executable(maintest1 modernOpenglLearn.cpp)

add_executable(cpptest cppPractice.cpp ../include/utilz/math/enums/linearAlgebraEnums.h ../include/utilz/math/algebra/objects/matrix.h ../include/utilz/math/algebra/linear_functions/transformation_matrices.h ../include/core/gl/shader/uniformHolder.h)



target_link_libraries(maintest1
        PRIVATE
        lenoEngineProgram)


target_link_libraries(maintest
        PRIVATE
        lenoEngineProgram)

target_link_libraries(cpptest
        PRIVATE
        lenoEngineProgram)


