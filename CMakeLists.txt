cmake_minimum_required(VERSION 3.4)
project(code_generator)

set(HEADERS_DIR "${PROJECT_SOURCE_DIR}/include")

option(BUILD_SHARED "build shared instead of static" ON)
set(CODE_GENERATOR_SHARED_LIBRARY ${BUILD_SHARED})
configure_file(${HEADERS_DIR}/code_generator/Config.h.in ${HEADERS_DIR}/include/code_generator/Config.h)

# 添加fmt的header only支持
add_definitions(-DFMT_HEADER_ONLY) 

IF (MSVC)
	add_compile_options("/utf-8")
ENDIF()

include_directories(${HEADERS_DIR})
include_directories(${PROJECT_SOURCE_DIR}/libs/fmt/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURCE_FILES)

IF (BUILD_SHARED)
	add_definitions(-DCODEC_GENERATOR_EXPORT)
	add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
	IF (WIN32)
		set_target_properties(${PROJECT_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
	ENDIF()
ELSE()
	add_library(${PROJECT_NAME} ${SOURCE_FILES})
ENDIF()  
  
install(TARGETS ${PROJECT_NAME} 
		RUNTIME DESTINATION bin
		LIBRARY DESTINATION lib
		ARCHIVE DESTINATION lib)

install(DIRECTORY ${HEADERS_DIR}/ DESTINATION include)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/libs/fmt/include DESTINATION include)