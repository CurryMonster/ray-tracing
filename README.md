# ray-tracing

In this repository, I am building a ray tracing engine. The source code (engine architecture) is based on Kevin Suffern's Ray Tracing from the Ground Up (2007). Majority of the source code (and implementation details) are from the book, but few components were altered for preference reasons. For example, Suffern uses raw pointers to achieve run-time polymorphism and manually deletes allocated memory (to mitigate/prevent memory leaks). Interestingly, C++11 introduced smart pointers, which take care of this issue. While implementing Suffern's engine, I prioritized "moderning" the source code and maintaining best practices. The images are rendered (pixel-by-pixel) using SDL2. In the "images" directory, there are 5-6 images rendered using this engine. These images consist of basic spheres with lights, color, and shading.  The project is built using CMake.   

As of 4/20/2022, I have implemented glossy specular reflection and am working to integrate realistic shadows.

Create and enter the build directory:
```
mkdir build
cd build
```

For Windows (MinGW-w64 compiler), enter:
```
cmake .. -G "MinGW Makefiles"
cmake --build .
```

To run the executable (on Windows), enter:
```
.\apps\app.exe
```
