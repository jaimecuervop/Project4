#ifndef PERSISTENCIAARBOL_H
#define PERSISTENCIAARBOL_H

#include "ArbolBinario.h"

using namespace std;

/*struct PesistenciaNodo {
    int secuencia;
    struct nodo* nodoarbol;
};*/

int manejoError(char* error, int code);
void guardarArbol(string nombre, ABB arbol);
void recuperarArbol(string nombre, ABB arbol);

#endif PERSISTENCIAARBOL_H