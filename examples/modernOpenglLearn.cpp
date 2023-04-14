#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include <thread>
#include "core/gl/shader/shaderProgram.h"
#include <filesystem>
#include "yaml-cpp/yaml.h"


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
    YAML::Node config = YAML::LoadFile("/home/leno/DevelopmentCenter/Projects/GameDev/Engines/LenoEngine/GLenoEngine/properties/engine_properties.yaml");

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
            1,0,0,1,
            0.5,1,0.5,1,
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

int main(){
    test2();
}