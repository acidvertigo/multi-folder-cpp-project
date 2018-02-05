#-------------------------------------------------------------------------------
#	CMAKE SETTINGS
#-------------------------------------------------------------------------------
CMAKE_MINIMUM_REQUIRED( VERSION 2.8 )
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

#-------------------------------------------------------------------------------
#	PROJECT SETTINGS
#-------------------------------------------------------------------------------
SET( PROJ_NAME      "app" )
SET( PROJ_PATH      ${CMAKE_SOURCE_DIR} )
SET( PROJ_OUT_PATH  ${CMAKE_BINARY_DIR} )
SET( PROJ_LIBRARIES "libsample.so" )
SET( PROJ_INCLUDES  "inc" )
PROJECT( ${PROJ_NAME} )
ENABLE_TESTING()

#-------------------------------------------------------------------------------
#	SOURCE CODE
#-------------------------------------------------------------------------------
FILE( GLOB_RECURSE PROJ_SOURCES src/*.cpp )
FILE( GLOB_RECURSE PROJ_HEADERS inc/*.h )

ADD_SUBDIRECTORY( ${CMAKE_SOURCE_DIR}/src/sample/ )
ADD_SUBDIRECTORY( ${CMAKE_SOURCE_DIR}/test/ )

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
ADD_EXECUTABLE( ${PROJ_NAME} ${PROJ_SOURCES} ${PROJ_SOURC})
TARGET_LINK_LIBRARIES( ${PROJ_NAME} ${PROJ_LIBRARIES} )

# Add debug postfix to executable name
SET_TARGET_PROPERTIES(app PROPERTIES DEBUG_POSTFIX "-debug")

# Use the automatically determined RPATH values
set_target_properties(${PROJ_NAME} PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)

#-------------------------------------------------------------------------------
#	DEFINE INSTALL FOLDERS
#-------------------------------------------------------------------------------
IF(CMAKE_BUILD_TYPE MATCHES "Release")
    INSTALL(TARGETS ${PROJ_NAME}
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/Release/
        LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib/Release/
        CONFIGURATIONS Release)
ELSE(CMAKE_BUILD_TYPE MATCHES "Release")
    INSTALL(TARGETS ${PROJ_NAME}
        RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin/Debug/
        LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib/Debug/
        CONFIGURATIONS Debug)
ENDIF(CMAKE_BUILD_TYPE MATCHES "Release")

INCLUDE(InstallRequiredSystemLibraries)