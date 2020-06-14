
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>
using namespace std;

struct nodo {
    int valor;
    struct nodo* izq, * der;
};

typedef struct nodo* ABB;


ABB crearNodo(int x)
{
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->valor= x;
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

void path(ABB& arbol, std::vector<int>& vPath, int valor)
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

int commonAncestor(ABB& arbol,int vlNodeA , int vlNodeB)
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
            vlCommonAncestor = bpath[i];
        }
    }
    return vlCommonAncestor;
}

void crearArbolBinario(ABB& arbol ,string str)
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


int main()
{
    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo

    ABB arbol = NULL;   // creado Arbol
    string s = "1 4 12 15 8 9 13 5 ";

    cout << "ingrese los elementos del arbol separados por espacio"<<endl;
    crearArbolBinario(arbol,s);
    cout << endl << endl;
    cout << commonAncestor(arbol, 5, 15) << endl << endl;
    cout << endl << endl;
    cout << commonAncestor(arbol, 4, 13) << endl << endl;
    system("pause");
    return 0;
}