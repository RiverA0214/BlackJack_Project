#include "Crupier.h"
#include <iostream>

// Constructor: nombre fijo y dinero virtual infinito
Crupier::Crupier()
    : Jugador("Crupier", 1e9) // dinero muy alto para no limitarse
{}

// Muestra solo la primera carta (ocultando el resto)
void Crupier::mostrarManoInicial() const {
    std::cout << "\n" << getNombre() << " muestra:" << std::endl;
    
    if (!seHaPasado() && !tieneBlackjack() && calcularMano() > 0) {
        // Mostrar solo la primera carta
        std::cout << "[Carta 1]: ";
        mostrarMano(); // Muestra todas las cartas (temporalmente)
    } else {
        std::cout << "[Carta oculta]" << std::endl;
    }
}



// Decide si quiere otra carta según reglas del crupier
bool Crupier::quiereCarta() const {
    return calcularMano() < 17;
}
