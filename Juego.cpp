#include "Juego.h"
#include <iostream>
#include <limits> // para limpiar el input

// Constructor: crea los jugadores con nombres y dinero inicial
Juego::Juego(int numJugadores) {
    for (int i = 0; i < numJugadores; ++i) {
        std::string nombre;
        std::cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        std::getline(std::cin, nombre);
        jugadores.emplace_back(nombre, 100.0); // dinero inicial fijo
    }
}

// Ejecuta una ronda completa
void Juego::iniciarRonda() {
    mazo = Mazo();      // nuevo mazo
    mazo.barajar();

    repartirCartasIniciales();
    jugarTurnos();
    turnoCrupier();
    determinarGanadores();
    mostrarResultados();

    // Preparar para la siguiente ronda
    for (auto& jugador : jugadores) {
        jugador.limpiarMano();
    }
    crupier.limpiarMano();
}

// Reparte 2 cartas a cada jugador y al crupier
void Juego::repartirCartasIniciales() {
    for (auto& jugador : jugadores) {
        jugador.recibirCarta(mazo.repartir());
        jugador.recibirCarta(mazo.repartir());
    }

    crupier.recibirCarta(mazo.repartir());
    crupier.recibirCarta(mazo.repartir());

    for (const auto& jugador : jugadores) {
        jugador.mostrarMano();
    }

    std::cout << "\nCrupier muestra:" << std::endl;
    crupier.mostrarManoInicial();
}

// Cada jugador toma sus decisiones
void Juego::jugarTurnos() {
    for (auto& jugador : jugadores) {
        while (!jugador.seHaPasado() && jugador.quiereCarta()) {
            std::cout << jugador.getNombre() << " pide carta." << std::endl;
            jugador.recibirCarta(mazo.repartir());
            jugador.mostrarMano();

            if (jugador.seHaPasado()) {
                std::cout << jugador.getNombre() << " se ha pasado de 21." << std::endl;
            }
        }
    }
}

// Turno automático del crupier
void Juego::turnoCrupier() {
    std::cout << "\nTurno del Crupier:" << std::endl;
    crupier.mostrarMano();

    while (crupier.quiereCarta()) {
        std::cout << "Crupier pide carta..." << std::endl;
        crupier.recibirCarta(mazo.repartir());
        crupier.mostrarMano();
    }

    if (crupier.seHaPasado()) {
        std::cout << "El Crupier se ha pasado de 21." << std::endl;
    } else {
        std::cout << "El Crupier se planta con " << crupier.calcularMano() << "." << std::endl;
    }
}

// Compara cada mano con el crupier
void Juego::determinarGanadores() {
    int valorCrupier = crupier.calcularMano();

    for (auto& jugador : jugadores) {
        int valorJugador = jugador.calcularMano();

        if (jugador.seHaPasado()) {
            std::cout << jugador.getNombre() << " pierde (se pasó)." << std::endl;
        } else if (crupier.seHaPasado()) {
            std::cout << jugador.getNombre() << " gana (crupier se pasó)." << std::endl;
        } else if (jugador.tieneBlackjack() && !crupier.tieneBlackjack()) {
            std::cout << jugador.getNombre() << " gana con Blackjack!" << std::endl;
        } else if (valorJugador > valorCrupier) {
            std::cout << jugador.getNombre() << " gana." << std::endl;
        } else if (valorJugador < valorCrupier) {
            std::cout << jugador.getNombre() << " pierde." << std::endl;
        } else {
            std::cout << jugador.getNombre() << " empata con el crupier." << std::endl;
        }
    }
}

// Muestra resultados finales (resumen simple)
void Juego::mostrarResultados() const {
    std::cout << "\n=== Resultados Finales ===" << std::endl;
    for (const auto& jugador : jugadores) {
        std::cout << jugador.getNombre() << ": " << jugador.calcularMano();
        if (jugador.seHaPasado()) {
            std::cout << " (Se pasó)";
        } else if (jugador.tieneBlackjack()) {
            std::cout << " (Blackjack)";
        }
        std::cout << std::endl;
    }

    std::cout << "Crupier: " << crupier.calcularMano();
    if (crupier.seHaPasado()) {
        std::cout << " (Se pasó)";
    } else if (crupier.tieneBlackjack()) {
        std::cout << " (Blackjack)";
    }
    std::cout << std::endl;
}
