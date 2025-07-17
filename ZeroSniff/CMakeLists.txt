# CMakeList.txt : CMake project for ZeroSniff, include source and define
# project specific logic here.
#

# Add source to this project's executable.

include_directories("C:/npcap/Include")
link_directories("C:/npcap/Lib/x64")


add_executable (ZeroSniff "ZeroSniff.cpp" "ZeroSniff.h" "src/hello.cpp" "src/UserInterfaceUtils.cpp" "include/UserInterfaceUtils.h")
target_link_libraries(ZeroSniff PRIVATE wpcap Packet Ws2_32)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ZeroSniff PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
