//LOPEZ LOPEZ BRANDON ADAIR
//22100190

#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Numero {
private:
    int Real;
    int Complejo;
    //solo considero los inputs, en este caso el usuario solo puede introducir numerador y denominador

public: //metodos
    Numero(int, int);//constructor
    void suma(Numero);
    void resta(Numero);
    void multiplicacion(Numero);
    void division(Numero);
};

Numero::Numero(int real, int complejo) : Real(real), Complejo(complejo) {} //constructor

void Numero::suma(Numero numero2) {

    int resultadoReal, resultadoComplejo;
    resultadoReal = Real + numero2.Real;
    resultadoComplejo = Complejo + numero2.Complejo;

    if (resultadoComplejo < 0) {
        if (resultadoComplejo < 0) {
            cout << endl << "El resultado es: " << resultadoReal << resultadoComplejo << 'i' << endl;
        }
    }
    else {
        if (resultadoComplejo == 1) {
            cout << endl << "El resultado es: " << resultadoReal << '+' << 'i' << endl;
        }
        else {
            cout << endl << "El resultado es: " << resultadoReal << '+' << resultadoComplejo << 'i' << endl;
        }

    }
}

void Numero::resta(Numero numero2) {
    int resultadoReal, resultadoComplejo;
    resultadoReal = Real - numero2.Real;
    resultadoComplejo = Complejo - numero2.Complejo;

    if (resultadoComplejo < 0) {
        cout << endl << "El resultado es: " << resultadoReal << resultadoComplejo << 'i' << endl;
    }
    else {
        if (resultadoComplejo == 1) {
            cout << endl << "El resultado es: " << resultadoReal << '+' << 'i' << endl;
        }
        else {
            cout << endl << "El resultado es: " << resultadoReal << '+' << resultadoComplejo << 'i' << endl;
        }
    }
}

void Numero::multiplicacion(Numero numero2) {

}

void Numero::division(Numero numero) {

}

bool validarInput(string primeraExpresion) {
    int posicionOperador = primeraExpresion.find('+' || '-'); //esta funcion en que posicion del string se encuentra un + - * /
    if (posicionOperador == 0 || posicionOperador == primeraExpresion.length() - 1) { // el / no puede estar en la posicion 0, ni puede estar al final
        cout << "Introduce una expresion correcta" << endl;
        return false;
    }
    else {
        return true;
    }
}

void Decodificador(string primeraExpresion, int numero1[], int r, int c, string i) {

    int PosicionOperador = primeraExpresion.find('+'); //esta funcion en que posicion del string se encuentra un + - * /
    int posicionOperador = primeraExpresion.find('-'); //esta funcion en que posicion del string se encuentra un + - * /
    if (PosicionOperador == true) {
        numero1[r] = stoi(primeraExpresion.substr(0, PosicionOperador)); //separa el string en formator fraccion, aqui obtiene el numerador (desde la posicion 0 hasta el /)
        numero1[c] = stoi(primeraExpresion.substr(PosicionOperador + 1)); //y aqui separa desde la posicion del slash lo que haya despues
    }
    else {
        numero1[r] = stoi(primeraExpresion.substr(0, posicionOperador)); //separa el string en formator fraccion, aqui obtiene el numerador (desde la posicion 0 hasta el /)
        numero1[c] = stoi(primeraExpresion.substr(posicionOperador + 1)); //y aqui separa desde la posicion del slash lo que haya despues
        numero1[c] = -numero1[c];
    }
}

int main() {

    cout << "NUMEROS COMPLEJOS CON OBJETOS" << endl << endl;
    cout << "Seleccione una operacion" << endl;
    cout << "1. Suma" << endl << "2. Resta" << endl << "3. Multiplicacion" << endl << "4. Division" << endl;

    int tipoOperacion, numero1[2], numero2[2];
    int real1{}, complejo1{}, real2{}, complejo2{};
    string primeraExpresion, segundaExpresion, i;
    cin >> tipoOperacion; //input para los cases

    switch (tipoOperacion) {
    case 1:
        cout << endl << "Suma" << endl;
        cout << "Ingrese la primera expresion (por ejemplo: 8+2i o 8-2i): ";
        cin >> primeraExpresion; //input de la fraccion
        if (validarInput(primeraExpresion)) { //pero solo si validarInput devuelve un true:
            Decodificador(primeraExpresion, numero1, 0, 1, i);
            real1 = numero1[0];
            complejo1 = numero1[1];

            cout << endl << "Ingrese la segunda expresion (por ejemplo: 8+2i o 8-2i): ";
            cin >> segundaExpresion; //input de la fraccion
            if (validarInput(segundaExpresion)) { //pero solo si validarInput devuelve un true:
                Decodificador(segundaExpresion, numero2, 0, 1, i);
                real2 = numero2[0];
                complejo2 = numero2[1];
                Numero expresion1(real1, complejo1);
                Numero expresion2(real2, complejo2);
                expresion1.suma(expresion2);
            }
        }
        break;

    case 2:
        cout << endl << "Resta" << endl;
        cout << "Ingrese la primera expresion (por ejemplo: 8+2i o 8-2i): ";
        cin >> primeraExpresion;
        if (validarInput(primeraExpresion)) {
            Decodificador(primeraExpresion, numero1, 0, 1, i);
            real1 = numero1[0];
            complejo1 = numero1[1];

            cout << real1 << complejo1;

            cout << endl << "Ingrese la segunda expresion (por ejemplo: 8+2i o 8-2i): ";
            cin >> segundaExpresion;
            if (validarInput(segundaExpresion)) {
                Decodificador(segundaExpresion, numero2, 0, 1, i);
                real2 = numero2[0];
                complejo2 = numero2[1];


                cout << real2 << complejo2;

                Numero expresion1(real1, complejo1);
                Numero expresion2(real2, complejo2);
                expresion1.resta(expresion2);
            }
        }
        break;

    case 3:
        cout << endl << "Multiplicacion" << endl;

        break;

    case 4:
        cout << endl << "Division" << endl;

        break;

    default:
        cout << "Seleccione una operacion valida" << endl;
        break;
    }
}