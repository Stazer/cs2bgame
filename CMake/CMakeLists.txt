CMake_Minimum_Required ( VERSION 2.8 )
Project ( Name )

Set ( CMAKE_CXX_FLAGS_DEBUG on )
Add_Definitions ( -g )
Add_Definitions ( -std=c++11 )

Include_Directories ( "${CMAKE_CURRENT_LIST_DIR}/../Dependencies/SFML/Include" )
Link_Directories ( "${CMAKE_CURRENT_LIST_DIR}/../Dependencies/SFML/Libraries" )

File ( GLOB SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/*" )
Add_Executable ( Application ${SOURCE} )
Target_Link_Libraries ( Application sfml-system sfml-window sfml-graphics sfml-audio )
