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

// Por defecto, un jugador siempre pide carta (sobrescribible)
bool Jugador::quiereCarta() const {
    // Esta lógica se debe redefinir en un derivado (jugador humano o IA)
    return calcularMano() < 17; // comportamiento por defecto
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
