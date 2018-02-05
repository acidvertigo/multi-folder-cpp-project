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
SET( PROJ_LIBRARIES "" )
SET( PROJ_INCLUDES  ${CMAKE_SOURCE_DIR}/inc )
PROJECT( ${PROJ_NAME} )
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

#-------------------------------------------------------------------------------
#	SOURCE CODE
#-------------------------------------------------------------------------------
FILE( GLOB_RECURSE PROJ_SOURCES *.cpp )
FILE( GLOB_RECURSE PROJ_HEADERS ${PROJ_INCLUDES}/${PROJ_NAME}/*.h )

#-------------------------------------------------------------------------------
#	ADDITIONAL LIBRARIES
#-------------------------------------------------------------------------------
# LIST(APPEND LIBRARIES
#
# )
# 
# # Remove duplicate library dependencies. 
# LIST(REMOVE_DUPLICATES LIBRARIES) 

#-------------------------------------------------------------------------------
#	COMPILE FLAGS
#-------------------------------------------------------------------------------
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_STANDARD 17)

if(MSVC)
	ADD_COMPILE_OPTIONS(/MP)
	ADD_COMPILE_OPTIONS(/std:c++17)
elseif(CMAKE_COMPILER_IS_GNUCXX)
	ADD_COMPILE_OPTIONS(-std=c++17)
endif(MSVC)

#-------------------------------------------------------------------------------
#	GENERATE EXECUTABLES
#-------------------------------------------------------------------------------
INCLUDE_DIRECTORIES( ${PROJ_INCLUDES} )
ADD_LIBRARY (${PROJ_NAME} SHARED ${PROJ_SOURCES})

# generate export header
INCLUDE( GenerateExportHeader )
GENERATE_EXPORT_HEADER(${PROJ_NAME} EXPORT_FILE_NAME ${CMAKE_BINARY_DIR}/exports/${PROJ_NAME}_export.h)

TARGET_LINK_LIBRARIES( ${PROJ_NAME} ${PROJ_LIBRARIES} )

#-------------------------------------------------------------------------------
#	DEFINE INSTALL FOLDERS
#-------------------------------------------------------------------------------
INSTALL(TARGETS ${PROJ_NAME}
    RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/Debug
    ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib/Debug
    LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib/Debug
    CONFIGURATIONS Debug)
INSTALL(TARGETS ${PROJ_NAME}
    RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/Release
    ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib/Release
    LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib/Release
    CONFIGURATIONS Release)