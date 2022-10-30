#include <unistd.h>
#include "clsDatosEntrada.h"

using namespace std;

int main(){
    int pid;
    int *datos=NULL;
    int *result=NULL;
    char *funciones=NULL;
    DatosEntrada de;

    datos = de.ObtenerDatos();
    funciones = de.ObtenerFunciones();
    result = de.ObtenerResultados();

    /*pid = fork();

    switch(pid){
        case -1:
            //error
        break;
        case 0:
            //hijo
            cout << "hijo " << getpid() << endl;
        break;
        default:
            //padre
            cout << "hijo " << getppid() << endl;
        break;
    }*/
}
