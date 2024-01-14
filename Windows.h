#ifndef WINDOWS_H_INCLUDED
#define WINDOWS_H_INCLUDED

#include <windows.h>
#include <string>
#include <iostream>

typedef int (*Msg)(HWND, LPCTSTR, LPCTSTR, UINT);

using namespace std;

class Windows {
private:
    HINSTANCE hDLL;

public:
    Windows();
    void msgBox(int &closed, string &message, string &title, int &type);
    ~Windows();
};

#endif // WINDOWS_H_INCLUDED
