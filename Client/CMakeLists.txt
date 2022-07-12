set(PROJECT_NAME OnlineSearch_Client)
set(CURRENT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

project(${PROJECT_NAME})

set( PROJECT_INCLUDE_PATH
	 ${CURRENT_PATH}
	 ${CURRENT_PATH}/include
	 ${ROOT_PATH}/interface/include )
	 
set( PROJECT_DEPENDENCIES 
	 OnlineSearch_Interface )

file( GLOB_RECURSE PROJECT_SOURCE_FILES
	  ${CURRENT_PATH}/*.h
	  ${CURRENT_PATH}/*.hpp
	  ${CURRENT_PATH}/*.cpp )

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

target_include_directories( ${PROJECT_NAME}
							PRIVATE
							${PROJECT_INCLUDE_PATH} )
							
target_link_libraries( ${PROJECT_NAME}
					   ${PROJECT_DEPENDENCIES} )

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD        # Adds a post-build event to MyTest
				   COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
				   "${ROOT_PATH}/libs/libmariadb.dll"      # <--this is in-file
				   $<TARGET_FILE_DIR:${PROJECT_NAME}>)                 # <--this is out-file path