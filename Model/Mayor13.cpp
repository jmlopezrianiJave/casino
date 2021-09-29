//
// Created by lufe0 on 7/05/2021.
//

#include "Mayor13.h"

float Mayor13::jugar(float gonzosApostar) {
    int opcion;
    float gonzosResultado;
    srand(time(NULL));
    // para calcular numero aleatorio variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
    numeroJugador = 1 + rand() % 13;
    cout << "Tu numero es: " << numeroJugador << endl;
    cout << "Deseas continuar?" << endl;
    cout << "1.Rendirse\n2.Continuar" << endl;
    cin >> opcion;
    if(opcion == 1){
        gonzosResultado = 0.5 * gonzosApostar;
        return gonzosResultado;
    }
    numeroCasino = 1 + rand() % 13;
    cout << "Numero del casino: " << numeroCasino << endl;
    gonzosResultado = calcularResultado(gonzosApostar);
    return gonzosResultado;
}


float Mayor13::calcularResultado(float gonzosApostar) {
    if(numeroJugador > numeroCasino){
        return gonzosApostar * 2;
    }
    else{
        return 0;
    }
}

Mayor13::~Mayor13() {

}
