//
// Created by lufe0 on 7/05/2021.
//

#include "Casino.h"

// Constructor que inicializa las ganancias y perdidas en cero
Casino::Casino() {
    cout << "Inicialice casino";
    // Inicia un jugador en el mapa para comenzar
    jugadoresMap.insert({1,new Jugador(1,"Pedro rodriguez", 500)});

    // Inicia  los juegos disponibles y los agrega al mapa de juegos
    Mayor13 * juego1 = new Mayor13();
    juegosDisponibles.push_back(juego1);
    DosColores * juego2 = new DosColores();
    juegosDisponibles.push_back(juego2);
    Ruleta * juego3 = new Ruleta();
    juegosDisponibles.push_back(juego3);

    // Agregar aqui los demas juegos
}

void Casino::agregarJugador(long id, string nombreJugador, double dinero) {
    // Se agrega jugador solo si no existe con anticipacion
    if(verExisteJugador(id) == false){
        float gonzosComprados = convertirPesosAGonzos(dinero);
        Jugador * nuevoJugador = new Jugador(id, nombreJugador, gonzosComprados);
        jugadoresMap.insert({nuevoJugador->getId(), nuevoJugador});
    }
    else {
        throw std::domain_error("El id recibido pertenece a un jugador existente\n");
    }
}

bool Casino::jugar(int idJuego, long idJugador, float gonzosApostar) {
    if (gonzosApostar < 1 ){
        throw std::domain_error("Debe apostar al menos 1 gonzo\n");
    }

    if (verExisteJugador(idJugador) == false){
        throw std::domain_error("El jugador con la identificacion recibida NO existe, no es posible jugar\n");
    }
    if (idJuego > juegosDisponibles.size()){
        throw std::domain_error("No existe el juego que desea jugar\n");
    }
    if (verPuedeContinuar(idJugador, gonzosApostar)== false){
        throw std::domain_error("No tienes saldo suficiente para jugar\n");
    }
    Juego * pJuego = juegosDisponibles.at(idJuego - 1);
    Jugador * jugadorActual = jugadoresMap[idJugador];
    float gonzosGanados = pJuego->jugar(gonzosApostar) - gonzosApostar;
    jugadorActual->actualizarGonzos(gonzosGanados);
    jugadorActual->aumentarJuegos();
    return(gonzosGanados >= 0);
}

void Casino::verInfoJugador(long idJugador){
    if(verExisteJugador(idJugador) == false){
        throw std::domain_error("El ID de jugador recibido no existe");
    }
    Jugador * jugadorMostrar = jugadoresMap[idJugador];
    jugadorMostrar->mostrarInfo();
}

bool Casino::verPuedeContinuar(int idJugador, float gonzosApostar) {
    if(verExisteJugador(idJugador) == false){
        throw std::domain_error("El ID de jugador recibido no existe");
    }
    Jugador * continuar = jugadoresMap[idJugador];
    if(continuar->getCantGonzos() < gonzosApostar){
        return false;
    }
    return true;
}

void Casino::retirarJugador(long idJugador) {
    if(verExisteJugador(idJugador) == false){
        throw std::domain_error("El ID de jugador recibido no existe");
    }
    Jugador * jugadorBorrar = jugadoresMap[idJugador];
    delete jugadorBorrar;
    jugadoresMap.erase(idJugador);
}

void Casino::recargarGonzos(long idJugador) {
    if(verExisteJugador(idJugador) == false){
        throw std::domain_error("El ID de jugador recibido no existe");
    }
    float plata;
    cout << "Ingrese la cantidad de dinero para recargar:" << endl;
    cin >> plata;
    if(plata <= 0){
        throw std::domain_error("Cantidad insuficiente para recargar");
    }
    float gonzosCon = convertirPesosAGonzos(plata);
    Jugador * jugadorRecargar = jugadoresMap[idJugador];
    jugadorRecargar->actualizarGonzos(gonzosCon);
}



bool Casino::verExisteJugador(long id) {
    for(map<long, Jugador*>::iterator it = jugadoresMap.begin(); it != jugadoresMap.end(); it++){
        if(it->first == id){
            return true;
        }
    }
    return false;
}

double Casino::convertirPesosAGonzos(double dinero) {
    return (dinero / 100);
}


Casino::~Casino() {
    cout << "Llame al destructor de casino \n";
    // Se libera la memoria del jugadores y de juegos
    for(map<long, Jugador*>::iterator it = jugadoresMap.begin(); it != jugadoresMap.end(); it++)
    {
        Jugador * jugadorTemp = jugadoresMap[it->first];
        delete jugadorTemp;
    }

    for(int i=0; i< juegosDisponibles.size(); i++)
    {
        Juego * juegoTemp = juegosDisponibles.at(i);
        delete juegoTemp;
    }
}