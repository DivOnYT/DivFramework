#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED


#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Window
{
public:

    Window(
        int optWindowStyle = 0,
        string className = "CLASS_NAME",
        string windowTitle = "Div Application",
        int windowStyle = WS_OVERLAPPEDWINDOW,
        int xPos = CW_USEDEFAULT,
        int yPos = CW_USEDEFAULT,
        int width = CW_USEDEFAULT,
        int height = CW_USEDEFAULT,
        HWND parent = 0,
        HMENU hMenu = nullptr,
        HINSTANCE instHandle = GetModuleHandle(nullptr),
        LPVOID addData = nullptr
    );

    ~Window();

    HWND getHWND();

    void mainloop();

private:
    HWND hParent;
    HINSTANCE hInstance;

    WNDCLASS wc = { };

    HWND hwnd;

    MSG msg;

};


#endif // WINDOW_H_INCLUDED
