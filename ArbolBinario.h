#pragma once
#ifndef ARBOLBINARIO_H
#include <vector>
#include <sstream>
#include "Nodo.h"

using namespace std;

class ArbolBinario
{
public:
    ABB crearNodo(int x);
    void insertar(ABB& arbol, int x);
    void preOrden(ABB arbol);
    void path(ABB& arbol, std::vector<int>& vPath, int valor);
    int commonAncestor(ABB& arbol, int vlNodeA, int vlNodeB);
    void crearArbolBinario(ABB& arbol, string str);
};

#endif // !ARBOLBINARIO_H


