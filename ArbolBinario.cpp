
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
#include "ArbolBinario.h"
#include "persistenciaArbol.h"

using namespace std;

ABB crearNodo(int x)
{
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->valor = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

void insertar(ABB& arbol, int x)
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
void preOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        cout << arbol->valor << " ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
void postOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->valor << " ";
    }
}


void ruta(ABB& arbol, std::vector<int>& vPath, int valor)
{
    vPath.push_back(arbol->valor);
    if (arbol->valor != valor)
    {
        if (arbol->valor < valor)
        {
            ruta(arbol->der, vPath, valor);
        }
        else
        {
            ruta(arbol->izq, vPath, valor);
        }
    }
}

int ancestroComun(ABB& arbol, int vlNodeA, int vlNodeB)
{
    int vlAncestroComun = 0;
    std::vector<int> apath;
    std::vector<int> bpath;
    int sizeSearch;

    if (arbol != nullptr)
    {
        ruta(arbol, apath, vlNodeA);
        ruta(arbol, bpath, vlNodeB);
    }

    if (apath.size() > bpath.size())
    {
        sizeSearch = bpath.size();
    }
    else
    {
        sizeSearch = apath.size();
    }

    for (int i = 0; i < sizeSearch; i++)
    {
        if (bpath[i] == apath[i])
        {
            vlAncestroComun = bpath[i];
        }
    }
    return vlAncestroComun;
}

void crearArbolBinario(ABB& arbol, string str)
{

    std::stringstream in(str);
    std::vector<int> a;
    int temp;
    while (in >> temp) {
        a.push_back(temp);
        insertar(arbol, a.back());
        a.pop_back();
    }
    postOrden(arbol);
    guardarArbol("lotos", arbol);

}
