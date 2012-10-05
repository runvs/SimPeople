cmake_minimum_required (VERSION 2.6)
project (SimPeople)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY    
     ${CMAKE_SOURCE_DIR}/../build/${CMAKE_PLATFORM})
SET (LIBRARY_OUTPUT_PATH 
	 ${CMAKE_SOURCE_DIR}/../build/${CMAKE_PLATFORM})
include_directories ("ext/exception/include")
include_directories ("ext/ptr_container/include")
include_directories ("ext/config/include")
include_directories ("ext/conversion/include")
add_subdirectory (SimPeople/SimPeopleLibrary)
add_subdirectory (SimPeople/SimPeopleImplementation)
#add_subdirectory (SimPeople/SimPeopleTest)
add_subdirectory (SimPeople/SimPeopleConsoleRunner)