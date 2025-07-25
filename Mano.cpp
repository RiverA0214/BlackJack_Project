#include "Mano.h"
#include <iostream>

// Añade una carta a la mano
void Mano::agregarCarta(const Carta& carta) {
    cartas.push_back(carta);
}

// Calcula el valor total considerando As como 11 o 1
int Mano::calcularValor() const {
    int total = 0;
    int ases = 0;

    for (const auto& carta : cartas) {
        total += carta.getValorNumerico();
        if (carta.getValor() == "A") {
            ases++;
        }
    }

    // Ajusta los Ases si se pasa de 21
    while (total > 21 && ases > 0) {
        total -= 10; // cambia un As de 11 a 1
        ases--;
    }

    return total;
}

// Retorna true si la mano tiene exactamente 2 cartas: un As + 10/figura
bool Mano::tieneBlackjack() const {
    if (cartas.size() != 2) return false;

    bool tieneAs = false;
    bool tieneDiez = false;

    for (const auto& carta : cartas) {
        if (carta.getValor() == "A") {
            tieneAs = true;
        } else if (carta.getValorNumerico() == 10) {
            tieneDiez = true;
        }
    }

    return tieneAs && tieneDiez;
}

// Retorna true si el valor de la mano es mayor que 21
bool Mano::seHaPasado() const {
    return calcularValor() > 21;
}

// Muestra todas las cartas en la mano
void Mano::mostrar() const {
    for (const auto& carta : cartas) {
        carta.mostrar();
    }
    std::cout << "Valor total: " << calcularValor() << "\n";
}


// Vacía la mano para una nueva ronda
void Mano::limpiar() {
    cartas.clear();
}
