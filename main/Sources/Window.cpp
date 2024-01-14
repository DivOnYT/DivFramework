#include "Window.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// ---------------------------------------------------------------->
// Procédure de fenêtre (callback)
// <----------------------------------------------------------------
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            // Ne rien faire pour ignorer la commande de fermeture
            return 0;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}



// ---------------------------------------------------------------->
// Coming from the Windows API
// https://learn.microsoft.com/fr-fr/windows/win32/api/winuser/nf-winuser-createwindowexw
// ALL THERE
// <----------------------------------------------------------------
Window::Window(
        int optWindowStyle,
        string className,
        string windowTitle,
        int windowStyle,
        int xPos,
        int yPos,
        int width,
        int height,
        HWND parent,
        HMENU hMenu,
        HINSTANCE instHandle,
        LPVOID addData
    )
{
    hParent = parent;
    hInstance = instHandle;

    wc.lpfnWndProc   = WindowProc;
    wc.hInstance     = hInstance;
    wc.lpszClassName = className.c_str();

    RegisterClass(&wc);

    // Create the window.

    hwnd = CreateWindowEx(
        optWindowStyle, //0x00000200L,                              // Optional window styles.
        className.c_str(),                    // Window class
        windowTitle.c_str(),    // Window text
        windowStyle,            // Window style

        // Size and position
        xPos, yPos, width, height,

        parent,       // Parent window
        hMenu,       // Menu
        instHandle,  // Instance handle
        addData        // Additional application data
        );

    if (hwnd == NULL)
    {
        cout << "Failed Creating Parent window !! " << endl;
        throw string("Failed Creating Parent window !! ");
    }
}


// ---------------------------------------------------------------->
// Boucle Principale permettant à la fênêtre
// de rester ouverte.
// <----------------------------------------------------------------

void Window::mainloop()
{
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

HWND Window::getHWND()
{
    return hParent;
}

// ---------------------------------------------------------------->
// Fermeture de la fênêtre et suppression
// de tous les pointeurs associés à la fênêtre
// <----------------------------------------------------------------
Window::~Window()
{
    DestroyWindow(hParent);
}




