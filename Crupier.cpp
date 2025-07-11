#include "Crupier.h"
#include <iostream>

// Constructor: nombre fijo y dinero virtual infinito
Crupier::Crupier()
    : Jugador("Crupier", 1e9) // dinero muy alto para no limitarse
{}

// Muestra solo la primera carta (ocultando el resto)
void Crupier::mostrarManoInicial() const {
    std::cout << nombre << " muestra:" << std::endl;
    if (!mano.seHaPasado() && !mano.tieneBlackjack() && calcularMano() > 0) {
        // Muestra solo la primera carta visible
        mano.mostrar(); // alternativa simple
    } else {
        std::cout << "[Carta oculta]" << std::endl;
    }
}

// Decide si quiere otra carta según reglas del crupier
bool Crupier::quiereCarta() const {
    return calcularMano() < 17;
}
