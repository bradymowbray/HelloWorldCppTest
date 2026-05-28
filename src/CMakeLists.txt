add_library(src OBJECT
  HelloWorld.cpp
)

###############################################################################
# find and link GSL libraries
# find_package(GSL COMPONENTS C CXX REQUIRED)
# target_link_libraries(src PUBLIC ${GSL_LIBRARIES})
# target_include_directories(src PUBLIC ${GSL_INCLUDE_DIR})

###############################################################################
# find and link HDF5 libraries
#find_package(HDF5 COMPONENTS CXX REQUIRED)
#link_directories( ${HDF5_LIBRARY_DIRS} )
#include_directories( ${HDF5_INCLUDE_DIR} )
#target_link_libraries(src PUBLIC ${HDF5_CXX_LIBRARIES})

###############################################################################
# find and link boost libraries
target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME} ${Boost_LIBRARIES})


target_include_directories(src PUBLIC ../include)
#target_include_directories(src PUBLIC ../src)
