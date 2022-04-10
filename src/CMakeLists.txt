set(HEADERS "${CMAKE_SOURCE_DIR}/include")

add_library(Utilities ./Utilities/Vector3D.cpp ./Utilities/Point3D.cpp)

target_include_directories(Utilities PUBLIC ../include)

target_compile_features(Utilities PUBLIC cxx_std_17)