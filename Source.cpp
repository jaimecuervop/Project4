
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "ArbolBinario.h"
#include "Nodo.h"
using namespace std;

int main()
{
    ArbolBinario arbol;   // creado Arbol
    string s = "1 4 12 15 8 9 13 5 ";
    ABB nodoRaiz =NULL;

    cout << "ingrese los elementos del arbol separados por espacio"<<endl;

    arbol.crearArbolBinario(nodoRaiz,s);
    cout << endl << endl;
    cout <<"El ancestro comun para los nodos 5 y 15 es "<< arbol.commonAncestor(nodoRaiz, 5, 15) << endl;
    cout <<"El ancestro comun para los nodos 4 y 13 es "<< arbol.commonAncestor(nodoRaiz, 4, 13) << endl;
    system("pause");
    return 0;
}