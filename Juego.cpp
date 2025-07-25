#include "Juego.h"
#include <iostream>
#include <limits> // para limpiar el input
#include <iomanip>  // para setw


//Apuestas
void Juego::pedirApuestas() {
    for (auto& jugador : jugadores) {
        jugador.apuesta(); 
    }
}


// Constructor: crea los jugadores con nombres y dinero inicial
Juego::Juego(int numJugadores) {
    for (int i = 0; i < numJugadores; ++i) {
        std::string nombre;
        std::cout << "Ingrese el nombre del jugador " << i + 1 << ": ";
        std::cout<<"\n";
        std::getline(std::cin, nombre);
        std::cout<<"\n";
        jugadores.emplace_back(nombre, 100.0); // dinero inicial fijo
    }
}

// Ejecuta una ronda completa
void Juego::iniciarRonda() {
    mazo = Mazo();      // nuevo mazo
    mazo.barajar();

    pedirApuestas();   

    repartirCartasIniciales();
    jugarTurnos();
    turnoCrupier();
    determinarGanadores();
    mostrarResultados();

    for (auto& jugador : jugadores) {
        jugador.limpiarMano();
    }
    crupier.limpiarMano();

    // Eliminar jugadores sin dinero
    for (auto it = jugadores.begin(); it != jugadores.end(); ) {
        if (it->getDinero() <= 0) {
            std::cout << it->getNombre() << " se ha quedado sin dinero y abandona el juego.\n";
            it = jugadores.erase(it);
        } else {
            ++it;
        }
}

if (jugadores.empty()) {
    std::cout << "Todos los jugadores se han quedado sin dinero. Fin del juego.\n";
    exit(0);
}

}


// Reparte 2 cartas a cada jugador y al crupier
void Juego::repartirCartasIniciales() {
    for (auto& jugador : jugadores) {
        jugador.recibirCarta(mazo.repartir());
        jugador.recibirCarta(mazo.repartir());
    }

    crupier.recibirCarta(mazo.repartir());

    for (const auto& jugador : jugadores) {
        jugador.mostrarMano();
    }

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
    crupier.recibirCarta(mazo.repartir());

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

        if (jugador.seHaPasado() && crupier.seHaPasado()) {
            std::cout << jugador.getNombre() << " y el Crupier se pasaron. Empate." << std::endl;
            std::cout << "Se retornan $" << jugador.getApuesta() << std::endl;
            jugador.sumarDinero(jugador.getApuesta());
        }
        else if (jugador.seHaPasado()) {
            std::cout << jugador.getNombre() << " pierde (se pasó)." << std::endl;
            std::cout << "Perdio $" << jugador.getApuesta() << std::endl;
        }
        else if (crupier.seHaPasado()) {
            std::cout << jugador.getNombre() << " gana (crupier se pasó)." << std::endl;
            jugador.sumarDinero(2 * jugador.getApuesta());
            std::cout << "Gano $" << 2 * jugador.getApuesta() << std::endl;
        }
        else if (jugador.tieneBlackjack() && !crupier.tieneBlackjack()) {
            std::cout << jugador.getNombre() << " gana con Blackjack!" << std::endl;
            jugador.sumarDinero(2 * jugador.getApuesta());
            std::cout << "Gano $" << 2 * jugador.getApuesta() << std::endl;
        }
        else if (valorJugador > valorCrupier) {
            std::cout << jugador.getNombre() << " gana." << std::endl;
            jugador.sumarDinero(2 * jugador.getApuesta());
            std::cout << "Gano $" << 2 * jugador.getApuesta() << std::endl;
        }
        else if (valorJugador < valorCrupier) {
            std::cout << jugador.getNombre() << " pierde." << std::endl;
            std::cout << "Perdio $" << jugador.getApuesta() << std::endl;
        }
        else {
            std::cout << jugador.getNombre() << " empata con el crupier." << std::endl;
            std::cout << "Empato, se retornan $" << jugador.getApuesta() << std::endl;
            jugador.sumarDinero(jugador.getApuesta());
        }
    }
}


// Muestra resultados finales
void Juego::mostrarResultados() const {
   int valorCrupier = crupier.calcularMano();

    std::cout << std::left << std::setw(15) << "Jugador"
            << std::setw(10) << "Puntos"
            << std::setw(10) << "Estado" << "\n";
    std::cout << "--------------------------------------\n";

    for (const auto& jugador : jugadores) {
        std::string estado;

        if (jugador.seHaPasado()) {
            estado = "Se pasó";
        }
        else if (jugador.tieneBlackjack()) {
            estado = "Blackjack";
        }
        else if (!crupier.seHaPasado() && jugador.calcularMano() == crupier.calcularMano()) {
            estado = "Empate";
        }
        else if(jugador.calcularMano() < valorCrupier && !crupier.seHaPasado()) {
            estado = "Perdió";
        }else{
            estado = "Ganó";
        }

        std::cout << std::left << std::setw(15) << jugador.getNombre()
                << std::setw(10) << jugador.calcularMano()
                << std::setw(10) << estado << "\n";
    }

}
