# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appWord_Frequently_Count_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appWord_Frequently_Count_autogen.dir\\ParseCache.txt"
  "appWord_Frequently_Count_autogen"
  )
endif()
