cmake_minimum_required(VERSION 2.8)
project( main )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
find_package( OpenCV REQUIRED )
add_executable(
	main
	main.cpp
	Board.cpp
	Square.cpp
	TerminalDisplay.cpp
	Screen.cpp
	UbuntuScreen.cpp
	)
target_link_libraries( main )
