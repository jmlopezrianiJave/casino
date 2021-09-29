#include "Ruleta.h"

float Ruleta::jugar(float gonzosApostar) {
    float gonzosResultado;
    srand(time(NULL));
    cout << "A que desea apostarle? (Numeros: 0 - 36)" << endl;
    cout << "1. primera docena" << endl; //primera docena no incluye a 0
    cout << "2. segunda docena" << endl;
    cout << "3. tercera docena" << endl;
    cout << "4. numero par" << endl;
    cout << "5. numero impar" << endl;
    cout << "6. numero especifico" << endl;
    cin >> tipoApuesta;
    numeroRuleta = rand() % 36;
    gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}

float Ruleta::calcularResultado(float gonzosApostar) {
    int numeroInd; //para recibir numero si jugaor apuesta a un numero individual
    switch(tipoApuesta){
        case 1:
            if(numeroRuleta > 0 && numeroRuleta <= 12){
                return gonzosApostar * 3;
            }
            break;
        case 2:
            if(numeroRuleta > 12 && numeroRuleta <= 24){
                return gonzosApostar * 3;
            }
            break;
        case 3:
            if(numeroRuleta > 24 && numeroRuleta <= 36){
                return gonzosApostar * 3;
            }
            break;
        case 4:
            if(numeroRuleta % 2 == 0){
                return gonzosApostar * 2;
            }
            break;
        case 5:
            if(numeroRuleta % 2 == 1){
                return gonzosApostar * 2;
            }
            break;
        case 6:
            cout << "Ingrese el numero al que desea apostar: " << endl;
            cin >> numeroInd;
            if (numeroRuleta == numeroInd){
                return gonzosApostar * 10;
            }
    }
}