#include "Nodo.h"
#include "iostream"
using namespace std;

Nodo::Nodo(int x)
{
	valor = x;
	izq = NULL;
	der = NULL;
}