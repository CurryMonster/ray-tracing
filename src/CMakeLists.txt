set(HEADER_UTILITIES ${CMAKE_SOURCE_DIR}/include/Utilities/Vector3D.hpp ${CMAKE_SOURCE_DIR}/include/Utilities/Point3D.hpp)
set(SOURCE_UTILITIES ${CMAKE_SOURCE_DIR}/src/Utilities/Vector3D.cpp ${CMAKE_SOURCE_DIR}/src/Utilities/Point3D.cpp)
add_library(Utilities ${SOURCE_UTILITIES} ${HEADER_UTILITIES})

target_include_directories(Utilities PUBLIC ${CMAKE_SOURCE_DIR}/include)

target_compile_features(Utilities PUBLIC cxx_std_17)