#include <iostream>
#include <string>
#include <windows.h>
#include <iostream>
#include "C:\Users\ARGON\OneDrive\Bureau\Programmation\C++\Windows API\MsgBox.h"
#include <winuser.h>
#include "C:\Users\ARGON\OneDrive\Bureau\Programmation\C++\Windows API\Window.h"
#include "C:\Users\ARGON\OneDrive\Bureau\Programmation\C++\Windows API\Button.h"

using namespace std;

int main()
{
    /*Window window;
    window.mainloop();*/

    int x = 20;
    int y = 20;

    string text = "Bonjour";
    long int style = WS_CHILD;
    int width = 200;
    int height = 200;

    Window window;


    window.mainloop();


    return 0;
}
