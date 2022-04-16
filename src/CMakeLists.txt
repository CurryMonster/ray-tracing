set(HEADER_UTILITIES 
    ${PROJECT_SOURCE_DIR}/include/Utilities/vector.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/point.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/color.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/normal.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/ray.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/record.hpp
)
set(SOURCE_UTILITIES 
    ${PROJECT_SOURCE_DIR}/src/Utilities/vector.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/point.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/color.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/normal.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/ray.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/record.cpp
)
add_library(Utilities STATIC ${SOURCE_UTILITIES} ${HEADER_UTILITIES})


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
add_library(Shapes STATIC ${SOURCE_SHAPES} ${HEADER_SHAPES})


set(HEADER_WORLD
    ${PROJECT_SOURCE_DIR}/include/World/world.hpp
    ${PROJECT_SOURCE_DIR}/include/World/view.hpp
)
set(SOURCE_WORLD
    ${PROJECT_SOURCE_DIR}/src/World/world.cpp
    ${PROJECT_SOURCE_DIR}/src/World/view.cpp
)
add_library(World STATIC ${SOURCE_WORLD} ${HEADER_WORLD})


set(HEADER_TRACERS
    ${PROJECT_SOURCE_DIR}/include/Tracers/tracer.hpp
    ${PROJECT_SOURCE_DIR}/include/Tracers/singlesphere.hpp
)
set(SOURCE_TRACERS
    ${PROJECT_SOURCE_DIR}/src/Tracers/tracer.cpp
    ${PROJECT_SOURCE_DIR}/src/Tracers/singlesphere.cpp
)
add_library(Tracers STATIC ${SOURCE_TRACERS} ${HEADER_TRACERS})


target_include_directories(Utilities PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Shapes PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(World PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Tracers PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_features(Utilities PRIVATE cxx_std_17)
target_compile_features(Shapes PRIVATE cxx_std_17)
target_compile_features(World PRIVATE cxx_std_17)
target_compile_features(Tracers PRIVATE cxx_std_17)