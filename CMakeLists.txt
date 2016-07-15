cmake_minimum_required(VERSION 2.8)
project( main )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lncurses")
find_package( Curses REQUIRED )
include_directories(${CURSES_INCLUDE_DIR})
add_executable(
	main
	Board.cpp
	Input.cpp
	MoveGenerator.cpp
	RookMoveGenerator.cpp
	Screen.cpp
	Square.cpp
	TerminalDisplay.cpp
	UbuntuScreen.cpp
	UserSession.cpp
	utilities.cpp
	main.cpp
	)
target_link_libraries( main ${CURSES_LIBRARIES} )
