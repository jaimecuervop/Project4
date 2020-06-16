#include "ArbolBinario.h"
#include "sqlite3.h"
#include "persistenciaArbol.h"


using namespace std;

int manejoError(char* error, int code)
{
	fprintf(stderr, "Error (%d): %s\n", code, error);
	exit(-1);
}


void guardarArbol(string nombre, ABB arbol) 
{
	sqlite3* db;
	sqlite3_stmt* query;

	char* error = 0;
	int res;
	char* sql = NULL;
	string strsql;
	int i;
	int secArbol = 0;

	if ((res = sqlite3_initialize()) != SQLITE_OK)
		manejoError(const_cast<char*>("No se puede inicializar SQLite"), res);
	if ((res = sqlite3_open_v2("test.db", &db, SQLITE_OPEN_READWRITE, NULL)) != SQLITE_OK)
		manejoError(const_cast<char*>("No puedo abrir la base de datos"), res);
	if ((res = sqlite3_prepare_v2(db, "SELECT SECUENCIA FROM ARBOL WHERE NOMBRE = ?", -1, &query, NULL)) != SQLITE_OK)
		manejoError(const_cast < char*>("No puedo ejecutar la consulta"), res);
	if ((res = sqlite3_bind_text(query, 1, nombre.c_str(), -1, SQLITE_STATIC)))
		manejoError(const_cast < char*>("No puedo vincular el argumento 1"), res);
    while ((res = sqlite3_step(query)) == SQLITE_ROW)
    {
        for (i = 0; i < sqlite3_column_count(query); ++i)
		{
			secArbol = sqlite3_column_int(query, i);
        }
    }

	if (secArbol == 0)
	{
		strsql = "INSERT INTO ARBOL(NOMBRE) VALUES(\'" + nombre + "');";
		res = sqlite3_exec(db, strsql.c_str(), NULL, 0, &error);
		if (res != SQLITE_OK) 
			manejoError(const_cast <char*>("No puedo ejecutar el insert"), res);
		while ((res  = sqlite3_step(query)) == SQLITE_ROW)
		{
			for (i = 0; i < sqlite3_column_count(query); ++i)
			{
				secArbol = sqlite3_column_int(query, i);
			}
		}
	}

	/* query cleanup */
	sqlite3_finalize(query);
	sqlite3_close_v2(db);
}

void recuperarArbol(string nombre, ABB arbol)
{

}