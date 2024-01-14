#include "MsgBox.h"

 using namespace std;


MsgBox::MsgBox(int &closed, string &message, string &title, int &type) {
    hDLL = LoadLibrary("User32.dll");
    if (hDLL == NULL) {
        std::cout << "Failed to load the library.\n";
        // Gérer l'erreur de chargement de la bibliothèque ici
    } else {
        std::cout << "Library loaded.\n";
    }
    Msg MsgBox = (Msg)GetProcAddress(hDLL, "MessageBoxA");
    MsgBox((HWND)closed, message.c_str() , title.c_str(), (UINT)type);
}

MsgBox::~MsgBox() {
    // Effectuez les opérations de nettoyage nécessaires ici
    cout << "Fin de la MsgBox";
}


    /* TEST MSGBOX FEATURE --------------------
    int closed = 0;
    int type =  0;  // max 6
    string message = "Salut bg";
    string title =  "Coucou";

    for (type; type<6; type++) {
        MsgBox window(closed, message, title, type);
        cout << type;
    }
    MsgBox window(closed, message, title, type);
    --------------------------------------------- */
