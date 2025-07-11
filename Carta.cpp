#include "Carta.h"
#include <iostream>

// Constructor
Carta::Carta(std::string palo, std::string valor, int valorNumerico)
    : palo(palo), valor(valor), valorNumerico(valorNumerico) {}

// Obtener el palo
std::string Carta::getPalo() const {
    return palo;
}

// Obtener el valor nominal (ej. "A", "2", "K", etc.)
std::string Carta::getValor() const {
    return valor;
}

// Obtener el valor según reglas de Blackjack
int Carta::getValorNumerico() const {
    return valorNumerico;
}

// Mostrar en formato "valor de palo"
void Carta::mostrar() const {
    std::cout << valor << " de " << palo << std::endl;
}
