set(PROJECT_NAME OnlineSearch_Interface)
set(CURRENT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

project(${PROJECT_NAME})

set( PROJECT_INCLUDE_PATH
	 ${ROOT_PATH}/include/mariadb-connector-c-3.3
	 ${CURRENT_PATH}
	 ${CURRENT_PATH}/include )

file( GLOB_RECURSE PROJECT_SOURCE_FILES
	  ${CURRENT_PATH}/*.h
	  ${CURRENT_PATH}/*.hpp
	  ${CURRENT_PATH}/*.cpp )

add_library(${PROJECT_NAME} 
			STATIC 
			${PROJECT_SOURCE_FILES})
			

target_include_directories( ${PROJECT_NAME}
							PRIVATE
							${PROJECT_INCLUDE_PATH} )

target_link_libraries( ${PROJECT_NAME}
					   PUBLIC
					   libmariadb )

set_target_properties(${PROJECT_NAME} 
					  PROPERTIES 
					  LINKER_LANGUAGE CXX)