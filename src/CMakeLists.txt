set(HEADER_UTILITIES 
    ${PROJECT_SOURCE_DIR}/include/Utilities/vector.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/point.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/color.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/normal.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/ray.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/record.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/math.hpp
)

set(SOURCE_UTILITIES 
    ${PROJECT_SOURCE_DIR}/src/Utilities/vector.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/point.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/color.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/normal.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/ray.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/record.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/math.cpp
)

set(HEADER_SHAPES
    ${PROJECT_SOURCE_DIR}/include/Shapes/shape.hpp
    ${PROJECT_SOURCE_DIR}/include/Shapes/plane.hpp
    ${PROJECT_SOURCE_DIR}/include/Shapes/sphere.hpp
)

set(SOURCE_SHAPES
    ${PROJECT_SOURCE_DIR}/src/Shapes/shape.cpp
    ${PROJECT_SOURCE_DIR}/src/Shapes/plane.cpp
    ${PROJECT_SOURCE_DIR}/src/Shapes/sphere.cpp
)

set(HEADER_WORLD
    ${PROJECT_SOURCE_DIR}/include/World/world.hpp
    ${PROJECT_SOURCE_DIR}/include/World/viewplane.hpp
)

set(SOURCE_WORLD
    ${PROJECT_SOURCE_DIR}/src/World/world.cpp
    ${PROJECT_SOURCE_DIR}/src/World/viewplane.cpp
)

set(HEADER_TRACERS
    ${PROJECT_SOURCE_DIR}/include/Tracers/tracer.hpp
    ${PROJECT_SOURCE_DIR}/include/Tracers/singlesphere.hpp
    ${PROJECT_SOURCE_DIR}/include/Tracers/multiple-objects.hpp
)

set(SOURCE_TRACERS
    ${PROJECT_SOURCE_DIR}/src/Tracers/tracer.cpp
    ${PROJECT_SOURCE_DIR}/src/Tracers/singlesphere.cpp
    ${PROJECT_SOURCE_DIR}/src/Tracers/multiple-objects.cpp
)

set(HEADER_SAMPLERS
    ${PROJECT_SOURCE_DIR}/include/Samplers/sampler.hpp
    ${PROJECT_SOURCE_DIR}/include/Samplers/jittered.hpp
)
    
set(SOURCE_SAMPLERS
    ${PROJECT_SOURCE_DIR}/src/Samplers/sampler.cpp
    ${PROJECT_SOURCE_DIR}/src/Samplers/jittered.cpp
)

set(HEADER_CAMERAS
    ${PROJECT_SOURCE_DIR}/include/Cameras/camera.hpp
    ${PROJECT_SOURCE_DIR}/include/Cameras/pinhole.hpp
)
    
set(SOURCE_CAMERAS
    ${PROJECT_SOURCE_DIR}/src/Cameras/camera.cpp
    ${PROJECT_SOURCE_DIR}/src/Cameras/pinhole.cpp
)

set(HEADER_LIGHTS
    ${PROJECT_SOURCE_DIR}/include/Lights/light.hpp
    ${PROJECT_SOURCE_DIR}/include/Lights/ambient.hpp
    ${PROJECT_SOURCE_DIR}/include/Lights/point-light.hpp
)
    
set(SOURCE_LIGHTS
    ${PROJECT_SOURCE_DIR}/src/Lights/light.cpp
    ${PROJECT_SOURCE_DIR}/src/Lights/ambient.cpp
    ${PROJECT_SOURCE_DIR}/src/Lights/point-light.cpp
)

set(HEADER_MATERIALS
    ${PROJECT_SOURCE_DIR}/include/Materials/material.hpp
    ${PROJECT_SOURCE_DIR}/include/Materials/matte.hpp
)

set(SOURCE_MATERIALS
    ${PROJECT_SOURCE_DIR}/src/Materials/material.cpp
    ${PROJECT_SOURCE_DIR}/src/Materials/matte.cpp
)

set(HEADER_BRDFS
    ${PROJECT_SOURCE_DIR}/include/BRDFs/brdf.hpp
    ${PROJECT_SOURCE_DIR}/include/BRDFs/lambertian.hpp
)

set(SOURCE_BRDFS
    ${PROJECT_SOURCE_DIR}/src/BRDFs/brdf.cpp
    ${PROJECT_SOURCE_DIR}/src/BRDFs/lambertian.cpp
)

set(HEADER_WINDOW ${PROJECT_SOURCE_DIR}/include/Window/window.hpp)
set(SOURCE_WINDOW ${PROJECT_SOURCE_DIR}/src/Window/window.cpp)

add_library(Utilities STATIC ${SOURCE_UTILITIES} ${HEADER_UTILITIES})
add_library(Shapes    STATIC ${SOURCE_SHAPES}    ${HEADER_SHAPES})
add_library(World     STATIC ${SOURCE_WORLD}     ${HEADER_WORLD})
add_library(Tracers   STATIC ${SOURCE_TRACERS}   ${HEADER_TRACERS})
add_library(Samplers  STATIC ${SOURCE_SAMPLERS}  ${HEADER_SAMPLERS})
add_library(Cameras   STATIC ${SOURCE_CAMERAS}   ${HEADER_CAMERAS})
add_library(BRDFs     STATIC ${SOURCE_BRDFS}     ${HEADER_BRDFS})
add_library(Lights    STATIC ${SOURCE_LIGHTS}    ${HEADER_LIGHTS})
add_library(Materials STATIC ${SOURCE_MATERIALS} ${HEADER_MATERIALS})
add_library(Window    STATIC ${SOURCE_WINDOW}    ${HEADER_WINDOW})

target_include_directories(Utilities PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Shapes    PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Tracers   PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(World     PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Cameras   PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Samplers  PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(BRDFs     PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Lights    PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Materials PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Window    PUBLIC ${PROJECT_SOURCE_DIR}/include)


target_link_libraries(World   PUBLIC SDL2-static)
target_link_libraries(Window  PUBLIC SDL2-static)
target_link_libraries(Cameras PUBLIC SDL2-static)

include_directories(${PROJECT_SOURCE_DIR}/extern/SDL2-2.0.20/include)

target_compile_features(Utilities PRIVATE cxx_std_17)
target_compile_features(Shapes    PRIVATE cxx_std_17)
target_compile_features(World     PRIVATE cxx_std_17)
target_compile_features(Tracers   PRIVATE cxx_std_17)
target_compile_features(Samplers  PRIVATE cxx_std_17)
target_compile_features(Cameras   PRIVATE cxx_std_17)
target_compile_features(Lights    PRIVATE cxx_std_17)
target_compile_features(BRDFs     PRIVATE cxx_std_17)
target_compile_features(Materials PRIVATE cxx_std_17)
target_compile_features(Window    PRIVATE cxx_std_17)
