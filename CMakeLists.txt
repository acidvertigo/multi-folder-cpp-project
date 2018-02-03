#-------------------------------------------------------------------------------
#	CMAKE SETTINGS
#-------------------------------------------------------------------------------
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

#-------------------------------------------------------------------------------
#	PROJECT SETTINGS
#-------------------------------------------------------------------------------
SET( PROJ_NAME      "sample" )
SET( PROJ_PATH      ${CMAKE_SOURCE_DIR} )
SET( PROJ_OUT_PATH  ${CMAKE_BINARY_DIR} )
SET( PROJ_LIBRARIES "sample" )
SET( PROJ_INCLUDES  "inc" )
PROJECT( ${PROJ_NAME} )

#-------------------------------------------------------------------------------
#	SOURCE CODE
#-------------------------------------------------------------------------------
FILE( GLOB_RECURSE PROJ_SOURCES src/*.cpp )
FILE( GLOB_RECURSE PROJ_HEADERS inc/*.h )


add_subdirectory({$PROJ_PATH}/src/sample)

#-------------------------------------------------------------------------------
#	ADDITIONAL LIBRARIES
#-------------------------------------------------------------------------------
# list(APPEND LIBRARIES
#
# )
# 
# # Remove duplicate library dependencies. 
# list(REMOVE_DUPLICATES LIBRARIES) 

#-------------------------------------------------------------------------------
#	COMPILE FLAGS
#-------------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

if(MSVC)
	add_compile_options(/MP)
	add_compile_options(/std:c++17)
elseif(CMAKE_COMPILER_IS_GNUCXX)
	add_compile_options(-std=c++17)
endif(MSVC)

#-------------------------------------------------------------------------------
#	GENERATE EXECUTABLES
#-------------------------------------------------------------------------------
INCLUDE_DIRECTORIES( ${PROJ_INCLUDES} )
ADD_EXECUTABLE( ${PROJ_NAME} ${PROJ_SOURCES} ${PROJ_SOURC})
TARGET_LINK_LIBRARIES( ${PROJ_NAME} ${PROJ_LIBRARIES} )