#ifndef ARBOLBINARIO_H // include guard
#define ARBOLBINARIO_H
#include <iostream>
#include <vector>

using namespace std;

struct nodo {
    int valor;
    struct nodo* izq, * der;
};

typedef struct nodo* ABB;

ABB crearNodo(int x);
void insertar(ABB& arbol, int x);
void preOrden(ABB arbol);
void postOrden(ABB arbol);
void ruta(ABB& arbol, std::vector<int>& vPath, int valor);
int ancestroComun(ABB& arbol, int vlNodeA, int vlNodeB);
void crearArbolBinario(ABB& arbol, string str);
#endif /*ARBOLBINARIO_H*/