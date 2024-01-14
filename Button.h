#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <string>
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include "C:\Users\ARGON\OneDrive\Bureau\Programmation\C++\Windows API\Window.h"

using namespace std;

class Button
{
public:
    Button(
           Window hParent,
           string text = "OK",
           long int hStyle = WS_TABSTOP,
           int hWidth = 100,
           int hHeight = 100,
           HMENU hMenu = nullptr
    );

    void place(
               int hX = 10,
               int hY = 10
               );

    ~Button();

private:
    HWND parent;
    string buttonText;
    long int style;
    int width;
    int height;
    int xPos;
    int yPos;
    HMENU menu;

};


#endif // BUTTON_H_INCLUDED
