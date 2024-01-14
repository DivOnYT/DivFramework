#include <string>
#include <iostream>
#include <windows.h>
#include <winuser.h>
#include "Button.h"
#include "Window.h"

using namespace std;


Button::Button(
               Window hParent,
               string text,
               long int hStyle,
               int hWidth,
               int hHeight,
               HMENU hMenu
               )
{
    buttonText = text;
    style = hStyle;
    width = hWidth;
    height = hHeight;
    parent = (HWND) hParent.getHWND();
    menu = hMenu;
}


void Button::place(int hX, int hY)
{
    xPos = hX;
    yPos = hY;
    HWND hwndButton = CreateWindow(
                                   "BUTTON",  // Predefined class; Unicode assumed
                                   buttonText.c_str(),      // Button text
                                   style,  // Styles
                                   xPos,         // x position
                                   yPos,         // y position
                                   width,        // Button width
                                   height,        // Button height
                                   parent,     // Parent window
                                   menu,       // No menu.
                                   (HINSTANCE)GetWindowLongPtr(parent, GWLP_HINSTANCE),
                                   NULL
                                   );      // Pointer not needed.
    if (hwndButton == NULL)
    {
        cout << "Failed Creating Button !! " << endl;
        throw string("Failed Creating Button !! ");
    }
}

Button::~Button()
{
}
