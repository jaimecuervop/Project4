
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "ArbolBinario.h"
using namespace std;

int main()
{
    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo

    ABB arbol = NULL;   // creado Arbol
    string s = "1 4 12 15 8 9 13 5 ";

    cout << "ingrese los elementos del arbol separados por espacio"<<endl;
    crearArbolBinario(arbol,s);
    cout << endl << endl;
    cout << ancestroComun(arbol, 5, 15) << endl << endl;
    cout << endl << endl;
    cout << ancestroComun(arbol, 4, 13) << endl << endl;
    system("pause");
    return 0;
}