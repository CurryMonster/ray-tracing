set(HEADER_UTILITIES 
    ${PROJECT_SOURCE_DIR}/include/Utilities/vector.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/point.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/color.hpp
    ${PROJECT_SOURCE_DIR}/include/Utilities/ray.hpp
)
set(SOURCE_UTILITIES 
    ${PROJECT_SOURCE_DIR}/src/Utilities/vector.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/point.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/color.cpp
    ${PROJECT_SOURCE_DIR}/src/Utilities/ray.cpp
)
add_library(Utilities STATIC ${SOURCE_UTILITIES} ${HEADER_UTILITIES})

target_include_directories(Utilities PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_features(Utilities PRIVATE cxx_std_17)