#ifndef CLSDATOSENTRADA_H_INCLUDED
#define CLSDATOSENTRADA_H_INCLUDED

#include <string>
using namespace std;

class DatosEntrada{
    public:
        int* ObtenerDatos();
        char* ObtenerFunciones();
        int* ObtenerResultados();
    private:
        bool ValidarDatos(string);
        bool ValidarFunciones(string);
        bool ValidarResultados(string);
};

#endif // CLSDATOSENTRADA_H_INCLUDED
