#include "ArbolBinario.h"
#include "Nodo.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;


ABB ArbolBinario::crearNodo(int x)
{
    ABB nuevoNodo;    
    nuevoNodo = ABB(new Nodo(x));
    return nuevoNodo;
}
void ArbolBinario::insertar(ABB& arbol, int x)
{
    if (arbol == NULL)
    {
        arbol = crearNodo(x);
    }
    else if (x < arbol->valor)
        insertar(arbol->izq, x);
    else if (x > arbol->valor)
        insertar(arbol->der, x);
}
void ArbolBinario::preOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        cout << arbol->valor << " ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
void ArbolBinario::path(ABB& arbol, std::vector<int>& vPath, int valor)
{
    vPath.push_back(arbol->valor);
    if (arbol->valor != valor)
    {
        if (arbol->valor < valor)
        {
            path(arbol->der, vPath, valor);
        }
        else
        {
            path(arbol->izq, vPath, valor);
        }
    }
}

int ArbolBinario::commonAncestor(ABB& arbol, int vlNodeA, int vlNodeB)
{
    int vlCommonAncestor = 0;
    std::vector<int> apath;
    std::vector<int> bpath;
    int sizeSearch;

    if (arbol != nullptr)
    {
        path(arbol, apath, vlNodeA);
        path(arbol, bpath, vlNodeB);
    }

    if (apath.size() > bpath.size())
    {
        sizeSearch = (int)bpath.size();
    }
    else
    {
        sizeSearch = (int)apath.size();
    }

    for (int i = 0; i < sizeSearch; i++)
    {
        if (bpath[i] == apath[i])
        {
            vlCommonAncestor = bpath[i];
        }
    }
    return vlCommonAncestor;
}

void ArbolBinario::crearArbolBinario(ABB& arbol, string str)
{

    std::stringstream in(str);
    std::vector<int> a;
    int temp;
    while (in >> temp) {
        a.push_back(temp);
        insertar(arbol, a.back());
        a.pop_back();
    }
    preOrden(arbol);
}