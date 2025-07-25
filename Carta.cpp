#include "Carta.h"
#include <iostream>
#include <iomanip> // para setw

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

// Mostrar en formato Carta
void Carta::mostrar() const {
    std::cout << "+-----------+\n";
    std::cout << "| " << std::left << std::setw(2) << valor << "        |\n";
    std::cout << "|           |\n";
    std::cout << "| " << std::setw(9) << palo << "|\n";
    std::cout << "+-----------+\n";
}
