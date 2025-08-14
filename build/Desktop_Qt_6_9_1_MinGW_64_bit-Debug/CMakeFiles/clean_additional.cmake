# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Windows-Based-Library-Management-System_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Windows-Based-Library-Management-System_autogen.dir\\ParseCache.txt"
  "Windows-Based-Library-Management-System_autogen"
  )
endif()
