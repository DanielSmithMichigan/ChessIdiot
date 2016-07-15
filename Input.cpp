#ifndef Input_cpp
#define Input_cpp
#include "Input.h"

    Input::Input() {

    }

    Input::~Input() {

    }

    char Input::getCharacter()
    {
        // disableBuffer();
        char out = getchar();
        cout << "DONE" << endl;
        // enableBuffer();
        return out;
    }

    void Input::disableBuffer()
    {   
        tcgetattr(fileno(stdin), &t); //get the current terminal I/O structure
        t.c_lflag &= ~ICANON; //Manipulate the flag bits to do what you want it to do
        tcsetattr(fileno(stdin), TCSANOW, &t); //Apply the new settings
    }


    void Input::enableBuffer()
    {
        tcgetattr(fileno(stdin), &t); //get the current terminal I/O structure
        t.c_lflag |= ICANON; //Manipulate the flag bits to do what you want it to do
        tcsetattr(fileno(stdin), TCSANOW, &t); //Apply the new settings
    }
#endif