file(GLOB CPPFILES  *.cpp)
file(GLOB HPPFILES  *.h)
add_library (SimPeopleImplementation ${CPPFILES} ${HPPFILES})
target_link_libraries (SimPeopleImplementation SimPeople)