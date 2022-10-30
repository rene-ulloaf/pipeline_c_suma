#include <stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <ctype.h>
#include <string.h>

#include "parametros.h"
#include "clsDatosEntrada.h"

using namespace std;

int* DatosEntrada :: ObtenerDatos(){
    int i,n,num,cl=0;
    int *datos=NULL;
    bool neg=false;

    ifstream f;
    string s;

    f.open(_ARCH_DAT, ios::in);

    if(f.is_open()){
        while(!f.eof()){
            f >> s;

            if(ValidarDatos(s)){
                cl++;
            }else{
                f.close();
                //exit;
            }
        }

        f.clear(ios::goodbit);
        f.seekg(0, ios::beg);
        datos = (int*) malloc(sizeof(int) * cl);
        cl = 0;

        while(!f.eof()){
            f >> s;
            num=0;
            n=0;

            for(i=0;i<s.length();i++){
                if(s[i] == '-'){
                    neg = true;
                }else{
                    switch(s[i]){
                        case 48:
                            n = 0;
                        break;
                        case 49:
                            n = 1;
                        break;
                        case 50:
                            n = 2;
                        break;
                        case 51:
                            n = 3;
                        break;
                        case 52:
                            n = 4;
                        break;
                        case 53:
                            n = 5;
                        break;
                        case 54:
                            n = 6;
                        break;
                        case 55:
                            n = 7;
                        break;
                        case 56:
                            n = 8;
                        break;
                        case 57:
                            n = 9;
                        break;
                    }

                    num = ((num * 10) + n);
                }
            }

            if(neg){
                num = num*-1;
            }

            datos[cl] = num;
            cl++;
        }
    }

    return datos;
}

char* DatosEntrada :: ObtenerFunciones(){
    int cl=0;
    char *func=NULL;

    ifstream f;
    string s;

    f.open(_ARCH_FUN, ios::in);

    if(f.is_open()){
        while(!f.eof()){
            f >> s;

            if(ValidarFunciones(s)){
                cl++;
            }else{
                f.close();
                //exit;
            }
        }

        f.seekg(0, ios::beg);
        f.clear(ios::goodbit);
        func = (char*) malloc(sizeof(char) * cl);
        cl = 0;

        while(!f.eof()){
            f >> s;

            if(!s.compare(_SUMA)){
                func[cl] = '+';
                f >> s;
            }else if(!s.compare(_RESTA)){
                func[cl] = '-';
                f >> s;
            }else if(!s.compare(_NEGAR)){
                func[cl] = 'N' ;
            }else if(!s.compare(_DIVIDIR)){
                func[cl] = '/';
                f >> s;
            }else if(!s.compare(_MULTIPLICAR)){
                func[cl] = '*';
                f >> s;
            }else if(!s.compare(_ELEVAR)){
                func[cl] = 'E';
                f >> s;
            }

            cl++;
        }
    }

    return func;
}

int* DatosEntrada :: ObtenerResultados(){
    int i,n,num,cl=0;
    int *res=NULL;
    bool neg=false;

    ifstream f;
    string s;

    f.open(_ARCH_FUN, ios::in);

    if(f.is_open()){
        while(!f.eof()){
            f >> s;

            if(ValidarResultados(s)){
                cl++;
            }else{
                f.close();
                //exit;
            }
        }

        f.clear(ios::goodbit);
        f.seekg(0, ios::beg);
        res = (int*) malloc(sizeof(int) * cl);
        cl = 0;

        while(!f.eof()){
            f >> s;
            num=0;
            n=0;

            if(!s.compare(_NEGAR)){
                num = -1;
            }else{
                f >> s;
            }

            if(num == 0){
                for(i=0;i<s.length();i++){
                    if(s[i] == '-'){
                        neg = true;
                    }else{
                        switch(s[i]){
                            case 48:
                                n = 0;
                            break;
                            case 49:
                                n = 1;
                            break;
                            case 50:
                                n = 2;
                            break;
                            case 51:
                                n = 3;
                            break;
                            case 52:
                                n = 4;
                            break;
                            case 53:
                                n = 5;
                            break;
                            case 54:
                                n = 6;
                            break;
                            case 55:
                                n = 7;
                            break;
                            case 56:
                                n = 8;
                            break;
                            case 57:
                                n = 9;
                            break;
                        }

                        num = ((num * 10) + n);
                    }
                }
            }

            if(neg){
                num = num*-1;
            }

            res[cl] = num;
            cl++;
        }
    }

    return res;
}

bool DatosEntrada :: ValidarDatos(string str){
    int i=0,n,num=0;
    bool neg = false;

    for(i=0;i<str.length();i++){
        if(!isdigit(str[i])){
            if(str[i] == '-'){
                neg = true;
            }else{
                return false;
            }
        }else{
            switch(str[i]){
                case 48:
                    n = 0;
                break;
                case 49:
                    n = 1;
                break;
                case 50:
                    n = 2;
                break;
                case 51:
                    n = 3;
                break;
                case 52:
                    n = 4;
                break;
                case 53:
                    n = 5;
                break;
                case 54:
                    n = 6;
                break;
                case 55:
                    n = 7;
                break;
                case 56:
                    n = 8;
                break;
                case 57:
                    n = 9;
                break;
            }
            num = ((num * 10) + n);
        }
    }

    if(neg){
        num = num*-1;
    }

    if((num < -32566) || (num > 32565)){
        return false;
    }

    return true;
}

bool DatosEntrada :: ValidarFunciones(string str){
    int i;

    for(i=0;i<str.length();i++){
        /*if(!s.compare(_SUMA)){
            f >> s;
        }else if(!s.compare(_RESTA)){
            f >> s;
        }else if(!s.compare(_NEGAR)){
            func[i] = 'N' ;
        }else if(!s.compare(_DIVIDIR)){
            f >> s;
        }else if(!s.compare(_MULTIPLICAR)){
            f >> s;
        }else if(!s.compare(_ELEVAR)){
            f >> s;
        }else{
            return false;
        }

        cl++;*/
    }

    return true;
}

bool DatosEntrada :: ValidarResultados(string str){
    int i;

    for(i=0;i<str.length();i++){
        /*if(!s.compare(_SUMA)){
            f >> s;
        }else if(!s.compare(_RESTA)){
            f >> s;
        }else if(!s.compare(_NEGAR)){
            func[i] = 'N' ;
        }else if(!s.compare(_DIVIDIR)){
            f >> s;
        }else if(!s.compare(_MULTIPLICAR)){
            f >> s;
        }else if(!s.compare(_ELEVAR)){
            f >> s;
        }else{
            return false;
        }

        cl++;*/
    }

    return true;
}
