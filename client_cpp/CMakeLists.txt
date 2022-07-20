set(PROJECT_NAME OnlineSearch_Client)
set(CURRENT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

project(${PROJECT_NAME})

find_package(Boost COMPONENTS filesystem REQUIRED)
find_package(OpenSSL REQUIRED)

set( PROJECT_INCLUDE_PATH
	 ${ROOT_PATH}/include/
	 ${ROOT_PATH}/include/thrift/cpp
	 ${ROOT_PATH}/include/mariadb
	 ${ROOT_PATH}/include/boost
	 ${ROOT_PATH}/include/openssl
	 ${ROOT_PATH}/thrift/gen-cpp
	 ${CURRENT_PATH}
	 ${CURRENT_PATH}/include )
	 
set( PROJECT_DEPENDENCIES 
	 thriftmdd
	${Boost_LIBRARIES} )

file( GLOB_RECURSE PROJECT_SOURCE_FILES
	  ${CURRENT_PATH}/*.h
	  ${CURRENT_PATH}/*.hpp
	  ${CURRENT_PATH}/*.cpp
	  ${ROOT_PATH}/thrift/gen-cpp/*.hpp
	  ${ROOT_PATH}/thrift/gen-cpp/*.cpp )

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

target_include_directories( ${PROJECT_NAME}
							PRIVATE
							${PROJECT_INCLUDE_PATH} )
							
target_link_libraries( ${PROJECT_NAME}
					   ${PROJECT_DEPENDENCIES} )

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)