cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
cmake_policy(VERSION 2.6)

project(cpp-experiments)

set(NAME cpp-experiments)

file(GLOB ROOT_SOURCE *.cpp)
file(GLOB ROOT_INLINE *.inl)
file(GLOB ROOT_HEADER *.hpp)
file(GLOB ROOT_C_SOURCE *.c)
file(GLOB ROOT_C_HEADER *.h)

source_group("Inline Files" FILES ${ROOT_INLINE})

add_executable(${NAME} 
	${ROOT_SOURCE} 
	${ROOT_INLINE} 
	${ROOT_HEADER}
	${ROOT_C_SOURCE}
	${ROOT_C_HEADER})

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
