<h1>LenoEngine</h1>



Instructions
To install and setup some system prerequisites are necessary<br>

On fedora<br>
- >su yum install mesa-libGLU-devel

On ubuntu<br>
- > sudo apt install cmake
- > sudo apt-get install xorg-dev
- > sudo apt install libglu1-mesa-dev freeglut3-dev



NOTE<br>
-in engine_properties.yaml file be sure to change path to your appropriate location

Dependencies<br>

* GLFW 
    -mkdir build
    -inside build *cmake ..*
    -make
* GLEW
    -in root just *make*
    - make install
    - make clean

All of this instructions can be run with ./setupLinux script in thirdparty folder




<h1>Tets</h1>

<p>Before running test do these steps:</p>

- <p style="color: #00D000;font-weight: bold">Change the definition of ENGINE_PROPERTIES_YAML in cmake file in tests folder. This property should match your path to this project</p>