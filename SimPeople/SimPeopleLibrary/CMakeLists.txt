file(GLOB CPPFILES  *.cpp)
file(GLOB HPPFILES  *.h)
add_library (SimPeopleLibrary ${CPPFILES} ${HPPFILES})