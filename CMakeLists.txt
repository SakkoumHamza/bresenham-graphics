cmake_minimum_required(VERSION 3.10)
project(demo)

set(CMAKE_CXX_STANDARD 11)

# Specify the path to the WinBGIm library and include directories
set(WINBGIM_INCLUDE_DIR "C:/TDM-GCC-32/include")  # Change to your actual include path
set(WINBGIM_LIB_DIR "C:/TDM-GCC-32/lib")          # Change to your actual lib path

# Add the include directories for WinBGIm
include_directories(${WINBGIM_INCLUDE_DIR})

# Add the executable
add_executable(demo ligne-cercle.cpp)

# Link with the WinBGIm library and other necessary libraries
target_link_libraries(demo -lbgi -lmingw32 -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32)

# Ensure the library directory is included in the link directories
link_directories(${WINBGIM_LIB_DIR})
