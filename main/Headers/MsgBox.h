#ifndef WINDOWS_H_INCLUDED
#define WINDOWS_H_INCLUDED

#include <windows.h>
#include <string>
#include <iostream>

typedef int (*Msg)(HWND, LPCTSTR, LPCTSTR, UINT);

using namespace std;

class MsgBox {
private:
    HINSTANCE hDLL;

public:
    MsgBox(int &closed, string &message, string &title, int &type);
    ~MsgBox();
};

#endif // WINDOWS_H_INCLUDED
