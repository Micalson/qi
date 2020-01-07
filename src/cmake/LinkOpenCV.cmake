macro(IncludeOpenCV)
include_directories("${CMAKE_SOURCE_DIR}/../../opencv/include")
include_directories("${CMAKE_SOURCE_DIR}/../../opencv/src/modules/core/include/")
include_directories("${CMAKE_BINARY_DIR}/../../opencv/build/")
include_directories("${CMAKE_BINARY_DIR}/../../opencv/build/include/")
endmacro()

macro(LinkOpencv target)
target_link_libraries(${target} debug "${LIB_OUTPUT_DIR}/Debug/opencv_core420d.lib" optimized "${LIB_OUTPUT_DIR}/Release/opencv_core420.lib")
endmacro()