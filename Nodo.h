#pragma once
#ifndef NODO_H
#define NODO_H

class Nodo
{

public:
	Nodo(int x);
	int valor;
	Nodo* izq, * der;
};

typedef class Nodo* ABB;
#endif // !NODO_H


