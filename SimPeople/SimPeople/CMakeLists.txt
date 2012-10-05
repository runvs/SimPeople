file(GLOB CPPFILES  *.cpp)
file(GLOB HPPFILES  *.h)
add_library (SimPeople ${CPPFILES} ${HPPFILES})