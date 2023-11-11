cmake_minimum_required(VERSION 3.12)
project(BallSimulator)

set (HEADER_FILES rlutil.h Ball.hpp BallSim.hpp RenderBall.hpp)


set(SOURCE_FILES  Ball.cpp BallSim.cpp RenderBall.cpp)
add_executable(BallSimulator ${SOURCE_FILES} ${HEADER_FILES} main.cpp)
set_property(TARGET BallSimulator PROPERTY CXX_STANDARD 20)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	target_compile_options(BallSimulator PRIVATE /W4 /permissive-)


elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_compile_options(BallSimulator PRIVATE -Wall -Wextra -pedantic )

elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	target_compile_options(BallSimulator PRIVATE -Wall -Wextra -pedantic)

endif()

find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
	message("Found clang-format at: " ${CLANG_FORMAT})
	unset(SOURCE_FILES_PATHS)
	foreach(SOURCE_FILE ${HEADER_FILES} ${SOURCE_FILES} main.cpp)
		get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
		message("The file " ${SOURCE_FILE} " full pathname is: " ${WHERE})
		set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
	endforeach()
	add_custom_target(
	ClangFormat
	COMMAND ${CLANG_FORMAT}
	-i
	-style=file
	${SOURCE_FILES_PATHS})
	add_dependencies(BallSimulator ClangFormat)

else()
	message("Didn't find clang-format." ${CLANG_FORMAT})
endif()







