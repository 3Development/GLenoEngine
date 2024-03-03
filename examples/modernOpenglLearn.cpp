
#include <iostream>
#include <thread>
#include "core/gl/shader/shaderProgram.h"
#include <filesystem>
#include "yaml-cpp/yaml.h"
#include "core/gl/vbo&vao/vaoVbo.h"
#include "utilz/math/algebra/linear_functions/transformation_matrices.h"
#include "core/engine/objects/model/modelGroup.h"
#include "glm/gtc/type_ptr.hpp"
#include "core/engine/render/holder/renderDataHolder.h"
#include "core/engine/render/renderEngine/renderController.h"
#include <glm/glm.hpp>
#include <chrono>

using namespace std::chrono;

/**
 * TIMER CLASS
 */

class Timer{

public:

    Timer(){
        _startPoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        stop();
    }

    void stop(){

        auto endPoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(_startPoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();


        auto duration = end - start;
        auto ms = duration * 0.001;
        auto seconds = duration * 0.000001;
        std::cout<<"______TIMER_______"<<std::endl;

        std::cout<<"Duration in micro  "<<duration<<std::endl;
        std::cout<<"Duration in milis  "<<ms<<std::endl;
        std::cout<<"Duration in seconds  "<<seconds<<std::endl;

        std::cout<<"______TIMER_______\n\n\n"<<std::endl;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock > _startPoint;
};

void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
    if(severity == GL_DEBUG_SEVERITY_HIGH || severity == GL_DEBUG_SEVERITY_MEDIUM){
        fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
                 ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
                 type, severity, message );
    }
}

void renderScene(float value){
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,nullptr);
}


static unsigned int CompileShader(const std::string& shader,unsigned int type){
    unsigned int vs = glCreateShader(type);
    const char* src = &shader[0];
    glShaderSource(vs,1,&src,nullptr);
    glCompileShader(vs);

    int result;
    glGetShaderiv(vs,GL_COMPILE_STATUS,&result);

    if(result == GL_FALSE){
        int length;
        glGetShaderiv(vs,GL_INFO_LOG_LENGTH,&length);
        char* message= (char*) alloca(sizeof(char) * length);
        glGetShaderInfoLog(vs,length,&length,message);
        std::cout<<"Failed to compile "<<(type==GL_VERTEX_SHADER?"vertex":" fragment")<<" shader "<<message<<std::endl;

        glDeleteShader(vs);
        return 0;

    }

    return vs;
}

static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader){
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(vertexShader,GL_VERTEX_SHADER);
    unsigned int f = CompileShader(fragmentShader,GL_FRAGMENT_SHADER);


    glAttachShader(program,vs);
    glAttachShader(program,f);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(f);

    return program;
}


void test(float* value){
    while(true){
        float a;
        std::cout<<"Upisi vrijednost "<<std::endl;
        std::cin>>a;

        *value = a;
    }
}

void test1(){
    if (!glfwInit())
    {
        // Initialization failed
        std::cout<<"Helldsadsao word!l"<<std::endl;
    }

    // Open buffer window and create its OpenGL context
    //Using buffer field of class window, this one will store the pointer to the window
    GLFWwindow* window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);

    if(window == NULL){
        glfwTerminate();
    }

    float value = -0.5f;
    std::thread first(test,&value);
    first.detach();

    glfwMakeContextCurrent(window);


    glewExperimental=true;
    if(glewInit() != GLEW_OK){
        std::cout<<"Glew not initialized "<<std::endl;
    }

    unsigned int buffer;
    float positions[6] = {
            -0.5f,-0.5f,
            0.0f,0.5f,
            0.5f,-0.5f
    };
    glGenBuffers(1,&buffer);

    glBindBuffer(GL_ARRAY_BUFFER,buffer);


    std::cout<<sizeof(positions);

    glBufferData(GL_ARRAY_BUFFER,6 * sizeof(float),positions,GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float) * 2,(const void*)0);

    std::string vertexShader = "#version 330 core\n"
                               "\n"
                               "layout(location = 0) in vec4 position;"
                               "void main(){\n"
                               "gl_Position = position;\n"
                               ""
                               ""
                               "}";


    std::string fragmentShader = "#version 330 core\n"
                                 "\n"
                                 "out vec4 color;\n"
                                 "void main(){\n"
                                 " color = vec4(1.0,0.5,1.0,1.0);\n"
                                 ""
                                 ""
                                 "}\n";
    unsigned int shader = CreateShader(vertexShader,fragmentShader);

    glUseProgram(shader);
    std::cout<<glGetString(GL_VERSION)<<std::endl;
    std::cout<<"Running"<<std::endl;
    while(!glfwWindowShouldClose(window)){
        renderScene(value);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
}

void test2(){
    YAML::Node config = YAML::LoadFile("/home/leno/DevelopmentCenter/Projects/GameDev/Engines/GLenoEngine/properties/engine_properties.yaml");

    if (!glfwInit())
    {
        // Initialization failed
        std::cout<<"Helldsadsao word!l"<<std::endl;
    }

    // Open buffer window and create its OpenGL context
    //Using buffer field of class window, this one will store the pointer to the window
    GLFWwindow* window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);

    if(window == NULL){
        glfwTerminate();
    }

    float value = -0.5f;
    std::thread first(test,&value);
    first.detach();

    glfwMakeContextCurrent(window);


    glewExperimental=true;
    if(glewInit() != GLEW_OK){
        std::cout<<"Glew not initialized "<<std::endl;
    }

    unsigned int vao;// GENERATE VAO WHICH WILL CONTAIN LAYOUT SPECIFICS FOR BUFFERS
    glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);

    unsigned int buffer;
    float positions[8] = {
            -0.5f,-0.5f, //0
            0.5f,0.5f, // 1
            0.5f,-0.5f, // 2
            -0.5f,0.5f, // 3
    };
    int indices[]={
            0,1,2,
            0,3,1
    };



    glGenBuffers(1,&buffer);
    glBindBuffer(GL_ARRAY_BUFFER,buffer);
    glBufferData(GL_ARRAY_BUFFER,6*2 * sizeof(float),positions,GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,sizeof(float) * 2,(const void*)0);


    float color[24] = {
            1,0,0.2,1,
            0.3,0,0.2,1,
            0,0,0,1,

            1,0,0,1,
            0.5,1,0.5,1,
            0,0,0,1,
    };
    unsigned int colorBuffer;
    glGenBuffers(1,&colorBuffer);
    glBindBuffer(GL_ARRAY_BUFFER,colorBuffer); // aktiviramo buffer
    glBufferData(GL_ARRAY_BUFFER,sizeof(float) * 4 * 3*2,color,GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,4,GL_FLOAT,GL_FALSE,sizeof(float) * 4,(const void*) 0);

    unsigned int ibo;

    glGenBuffers(1,&ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(int) * 6 , indices,GL_STATIC_DRAW);

    std::string root = std::string(config["resourceRootDir"].as<std::string>());
    std::string vertex = std::string(root).append("shaders/basic/basicShader.vert");
    std::string fragment = std::string(root).append("shaders/basic/basicShader.frag");

    ShaderProgram shaderProgram(vertex.c_str(),fragment.c_str());

    shaderProgram.initProgram();

    shaderProgram.createShaders();

    shaderProgram.activateProgram();

    std::cout<<glGetString(GL_VERSION)<<std::endl;
    std::cout<<"Running"<<std::endl;
    while(!glfwWindowShouldClose(window)){
        renderScene(value);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

}

void test3(){
    YAML::Node config = YAML::LoadFile("/home/leno/DevelopmentCenter/Projects/GameDev/Engines/GLenoEngine/properties/engine_properties.yaml");
    if (!glfwInit())
    {
        // Initialization failed
        std::cout<<"Helldsadsao word!l"<<std::endl;
    }

    // Open buffer window and create its OpenGL context
    //Using buffer field of class window, this one will store the pointer to the window
    GLFWwindow* window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);

    if(window == NULL){
        glfwTerminate();
    }

    float value = -0.5f;
    std::thread first(test,&value);
    first.detach();

    glfwMakeContextCurrent(window);


    glewExperimental=true;
    if(glewInit() != GLEW_OK){
        std::cout<<"Glew not initialized "<<std::endl;
    }

    glEnable              ( GL_DEBUG_OUTPUT );
    glDebugMessageCallback( MessageCallback, 0 );

    void* vao5= alloca(sizeof(VAO_5));

    initializeVao5Object(vao5,true);


    VAO_5 vao5C=*(VAO_5*)vao5;


    float positions[12] = {
            -0.5f,-0.5f,0, //0
            0.5f,0.5f,0, // 1
            0.5f,-0.5f,0, // 2
            -0.5f,0.5f,0 // 3
    };
    int indices[]={
            0,1,2,
            0,3,1
    };


    float color[24] = {
            1,0,0.2,1,
            0.3,1,0.2,1,
            0,0,0,1,

            1,0,0,1,
            0.5,1,0.5,1,
            0,0,0,1,
    };
    try{
        initializeVboObjectAndSaveItAtIndexAttrPointer(&vao5C, positions,sizeof(float)*12 ,GL_ARRAY_BUFFER,GL_FLOAT,0,3,sizeof(float)*3);
        initializeVboObjectAndSaveItAtIndexAttrPointer(&vao5C, color,sizeof(float)*24 ,GL_ARRAY_BUFFER,GL_FLOAT,1,4,sizeof(float)*4);
        initializeVboObjectAndSaveItAtIndexAttrPointer(&vao5C, indices,sizeof(float)*6 ,GL_ELEMENT_ARRAY_BUFFER,GL_FLOAT,-1,-1,-1);

    }catch (VboVaoEnums::ErrorCodes e){
        if (e == VboVaoEnums::VA0_NO_FREE_SLOT_IN_VBO_ARRAY){
            std::cout<<"VAO_NO_FREE_SLOT_IN_VBO_ARRAY";
            return;
        }
    }



    std::string root = std::string(config["resourceRootDir"].as<std::string>());
    std::string vertex = std::string(root).append("shaders/basic/basicShader.vert");
    std::string fragment = std::string(root).append("shaders/basic/basicShader.frag");

    ShaderProgram shaderProgram(vertex.c_str(),fragment.c_str());

    shaderProgram.initProgram();

    shaderProgram.createShaders();

    shaderProgram.activateProgram();


    glm::mat4 modelMatrix = glm::perspective(glm::radians(45.0f),1024.f/768.f,0.1f,300.0f);
    glm::mat4 translation = glm::translate(modelMatrix,glm::vec3(0.1,0,1));

    Mat4x4 mat4X4;
    Mat4x4 mat4X4translation;
    Mat4x4 mat4X4translation3;
    Mat4x4 mat4X4rotation;

    initIdentityMatrix4x4(&mat4X4);
    initIdentityMatrix4x4(&mat4X4translation);
    initIdentityMatrix4x4(&mat4X4translation3);

    Vec3 vec3Scale;
    vec3Scale.x = 2;
    vec3Scale.y = 1;
    vec3Scale.z = 1;
    createScaleMatrix4x4(&mat4X4,&vec3Scale);

    int location= glGetUniformLocation(shaderProgram.getProgramId(),"translationM");
    int projectionMatrix= glGetUniformLocation(shaderProgram.getProgramId(),"projectionM");
    int rotationMatrix= glGetUniformLocation(shaderProgram.getProgramId(),"rotationM");





    Vec3 vector3;
    Vec3 vector32;
    Mat4x4 projection;
    createPerspectiveMatrix4x4(&projection,1024,768,45,2,500);

    glUniformMatrix4fv(projectionMatrix,1,GL_FALSE,&projection.matrix[0]);

    std::cout<<glGetString(GL_VERSION)<<std::endl;
    vector3.x=0.01;
    vector3.z=-5;
    vector32.z=-5;
    Quaternion quaternion{0};


    float angle = 0;

    int sign = 1;

    bool deacitave = false;

    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);


        glfwPollEvents();
        prepareVaoForDrawing(&vao5C);

        createUnitQuaternionForRotation(1,1,1,angle,&quaternion);

        createScaleMatrix4x4(&mat4X4,&vec3Scale);
        createTranslationMatrix4x4(&mat4X4translation,&vector3);
        createMat4x4FromQuaternionRotation(&quaternion,&mat4X4rotation);


        Mat4x4 n = mat4X4 * &mat4X4translation;
        glUniformMatrix4fv(location,1,GL_FALSE,&n.matrix[0]);
        glUniformMatrix4fv(rotationMatrix,1,GL_FALSE,&mat4X4rotation.matrix[0]);


        drawVaoUsingIndices(6);


        angle+=0.1f;

        vector3.x=0.6;
        vector32.x = 0;
        vector3.y  = 0.9f;
        vector32.y = 1;
        vector32.y = 0;


        createUnitQuaternionForRotation(1,1,1,angle,&quaternion);

        createScaleMatrix4x4(&mat4X4,&vec3Scale);
        createTranslationMatrix4x4(&mat4X4translation3,&vector32);
        createMat4x4FromQuaternionRotation(&quaternion,&mat4X4rotation);


        glUniformMatrix4fv(location,1,GL_FALSE,&mat4X4translation3.matrix[0]);
        glUniformMatrix4fv(rotationMatrix,1,GL_FALSE,&mat4X4rotation.matrix[0]);

        drawVaoUsingIndices(6);
        deactivateAndUnbindAllFromVao(&vao5C);


        glfwSwapBuffers(window);

    }
}


void test4(){
    YAML::Node config = YAML::LoadFile("/home/leno/DevelopmentCenter/Projects/GameDev/Engines/GLenoEngine/properties/engine_properties.yaml");
    if (!glfwInit())
    {
        // Initialization failed
        std::cout<<"Helldsadsao word!l"<<std::endl;
    }

    // Open buffer window and create its OpenGL context
    //Using buffer field of class window, this one will store the pointer to the window
    GLFWwindow* window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);

    if(window == NULL){
        glfwTerminate();
    }

    float value = -0.5f;
    std::thread first(test,&value);
    first.detach();

    glfwMakeContextCurrent(window);


    glewExperimental=true;
    if(glewInit() != GLEW_OK){
        std::cout<<"Glew not initialized "<<std::endl;
    }

    glEnable( GL_DEBUG_OUTPUT );
    glDebugMessageCallback( MessageCallback, 0 );


    std::string root = std::string(config["resourceRootDir"].as<std::string>());
    std::string vertex = std::string(root).append("shaders/basic/basicShader.vert");
    std::string fragment = std::string(root).append("shaders/basic/basicShader.frag");

    ShaderProgram shaderProgram(vertex.c_str(),fragment.c_str());

    int slots = 3 * 3;
    ModelGroup<2, 3 * 3,VAO_5> entityGroup;



    shaderProgram.initProgram();

    shaderProgram.createShaders();

    entityGroup.initVao5(true);
    VAO_5* vao5C = entityGroup.getVao5();

    float positions[12] = {
            -0.5f,-0.5f,0, //0
            0.5f,0.5f,0, // 1
            0.5f,-0.5f,0, // 2
            -0.5f,0.5f,0 // 3
    };
    int indices[]={
            0,1,2,
            0,3,1
    };


    float color[24] = {
            1,0,0.2,1,
            0.3,1,0.2,1,
            0,0,0,1,

            1,0,0,1,
            0.5,1,0.5,1,
            0,0,0,1,
    };
    try{
        initializeVboObjectAndSaveItAtIndexAttrPointer(vao5C, positions,sizeof(float)*12 ,GL_ARRAY_BUFFER,GL_FLOAT,0,3,sizeof(float)*3);
        initializeVboObjectAndSaveItAtIndexAttrPointer(vao5C, color,sizeof(float)*24 ,GL_ARRAY_BUFFER,GL_FLOAT,1,4,sizeof(float)*4);
        initializeVboObjectAndSaveItAtIndexAttrPointer(vao5C, indices,sizeof(float)*6 ,GL_ELEMENT_ARRAY_BUFFER,GL_FLOAT,-1,-1,-1);

    }catch (VboVaoEnums::ErrorCodes e){
        if (e == VboVaoEnums::VA0_NO_FREE_SLOT_IN_VBO_ARRAY){
            std::cout<<"VAO_NO_FREE_SLOT_IN_VBO_ARRAY";
            return;
        }
    }


    entityGroup.setActivateVaoFuncType([](VAO_5* vao5){
        prepareVaoForDrawing(vao5);
    });


    entityGroup.setEntityDrawFuncType([&shaderProgram](ENTITIES_GROUP_DATA data,const ENTITIES_GROUP_ACTIVE& activeEntities,const UniformsHolder* uniformsHolder1){


    });

    shaderProgram.activateProgram();

    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);

        {
            entityGroup.activateVao();
            entityGroup.draw();
        }

        glfwPollEvents();

        drawVaoUsingIndices(6);


        glfwSwapBuffers(window);

    }
}


void test5(){
    MainGLRenderObject renderDataHolder;
}

int main(){
    test3();
}