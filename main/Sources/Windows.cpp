#include "Windows.h"

 using namespace std;

Windows::Windows() {
    std::cout << "Test\n";
    hDLL = LoadLibrary("User32.dll");
    if (hDLL == NULL) {
        std::cout << "Failed to load the library.\n";
        // G�rer l'erreur de chargement de la biblioth�que ici
    } else {
        std::cout << "Library loaded.\n";
    }
}

void Windows::msgBox(int &closed, string &message, string &title, int &type) {
    Msg MsgBox = (Msg)GetProcAddress(hDLL, "MessageBoxA");
    MsgBox((HWND)closed, message.c_str() , title.c_str(), (UINT)type);
    FreeLibrary(hDLL);
}


Windows::~Windows() {
    // Effectuez les op�rations de nettoyage n�cessaires ici
    cout << "Fin de la Windows";
}
