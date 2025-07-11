#include "Mazo.h"
#include <algorithm> // std::shuffle
#include <random>    // std::default_random_engine
#include <chrono>    // std::chrono::system_clock

// Constructor: crea las 52 cartas
Mazo::Mazo() {
    std::vector<std::string> palos = {"Corazones", "Diamantes", "Tréboles", "Picas"};
    std::vector<std::string> valores = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    for (const auto& palo : palos) {
        for (const auto& valor : valores) {
            int valorNumerico;

            if (valor == "A") valorNumerico = 11;
            else if (valor == "J" || valor == "Q" || valor == "K") valorNumerico = 10;
            else valorNumerico = std::stoi(valor);

            cartas.emplace_back(palo, valor, valorNumerico);
        }
    }
}

// Baraja las cartas
void Mazo::barajar() {
    // Semilla aleatoria con reloj del sistema
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(cartas.begin(), cartas.end(), std::default_random_engine(static_cast<unsigned>(seed)));
}

// Reparte la última carta del vector (como si fuera la parte superior del mazo)
Carta Mazo::repartir() {
    if (cartas.empty()) {
        throw std::out_of_range("No hay más cartas en el mazo");
    }

    Carta carta = cartas.back();
    cartas.pop_back();
    return carta;
}

// Número de cartas restantes
int Mazo::cartasRestantes() const {
    return static_cast<int>(cartas.size());
}
