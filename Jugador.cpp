#include "Jugador.h"
#include <iostream>

// Constructor
Jugador::Jugador(std::string nombre, double dineroInicial)
    : nombre(nombre), dinero(dineroInicial) {}

// Recibe una carta
void Jugador::recibirCarta(const Carta& carta) {
    mano.agregarCarta(carta);
}

// Calcula el valor de la mano
int Jugador::calcularMano() const {
    return mano.calcularValor();
}

// Muestra la mano del jugador
void Jugador::mostrarMano(bool mostrarTodas) const {
    std::cout << nombre << " tiene:" << std::endl;
    if (mostrarTodas) {
        mano.mostrar();
    } else {
        // Muestra solo la primera carta (útil para el crupier)
        if (!mano.seHaPasado() && mano.tieneBlackjack()) {
            std::cout << "Blackjack!" << std::endl;
        } else {
            // Simulación: mostrar solo una carta
            std::cout << "[Carta oculta]" << std::endl;
        }
    }
}

bool Jugador::quiereCarta() const {
    int seleccion;
    std::cout<<"\n"<<"1. Pedir\n2.Quedarse"<<std::endl;
    std::cin>>seleccion;
    if(seleccion==1){
        return true;
    }
    else{
        return false;
    }
}

// Retorna true si tiene blackjack
bool Jugador::tieneBlackjack() const {
    return mano.tieneBlackjack();
}

// Retorna true si se pasó de 21
bool Jugador::seHaPasado() const {
    return mano.seHaPasado();
}

// Limpia la mano para nueva ronda
void Jugador::limpiarMano() {
    mano.limpiar();
}

// Retorna el nombre
std::string Jugador::getNombre() const {
    return nombre;
}
double Jugador::apuesta(){
    double saldoApuesta;
    std::cout<<"Saldo disponible: $"<<getDinero()<<std::endl;
    std::cout<<"Ingrese apuesta: "<<std::endl;
    std::cin>>saldoApuesta;
    if(saldoApuesta>getDinero()){
        std::cout<<"Apostando todo en la cuenta $"<<getDinero()<<std::endl;
        setApuesta(getDinero());
        setDinero(0);
        return getDinero();
    }else{
        std::cout<<"Apostaste $"<<saldoApuesta<<" Buena Suerte"<<std::endl;
        setApuesta(saldoApuesta);
        setDinero(getDinero()-saldoApuesta);
        return saldoApuesta;
    }
}
void Jugador::setApuesta(double apuesta){
    apuestaActual=apuesta;
}
void Jugador::setDinero(double ganancia){
    dinero=ganancia+getDinero();
}
