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
)
set(SOURCE_SHAPES
    ${PROJECT_SOURCE_DIR}/src/Shapes/shape.cpp
    ${PROJECT_SOURCE_DIR}/src/Shapes/plane.cpp
)
add_library(Shapes STATIC ${SOURCE_SHAPES} ${HEADER_SHAPES})

target_include_directories(Utilities PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(Shapes PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_features(Utilities PRIVATE cxx_std_17)