#include "Jugador.h"
#include <iostream>
#include <limits>

Jugador::Jugador(const std::string& nombre, double dineroInicial)
    : nombre(nombre), dinero(dineroInicial), apuestaActual(0) {}

// ======== Dinero y Apuestas ========

void Jugador::setApuesta(double apuesta) {
    apuestaActual = apuesta;
}

double Jugador::getApuesta() const {
    return apuestaActual;
}

void Jugador::setDinero(double nuevoSaldo) {
    dinero = nuevoSaldo;
}

void Jugador::sumarDinero(double cantidad) {
    dinero += cantidad;
}

double Jugador::getDinero() const {
    return dinero;
}

double Jugador::apuesta() {
    double cantidad;
    std::cout << "\n" << nombre << ", tu saldo es: $" << dinero << std::endl;

    while (true) {
        std::cout << "¿Cuánto deseas apostar? ";
        std::cin >> cantidad;

        if (std::cin.fail() || cantidad <= 0 || cantidad > dinero) {
            std::cin.clear(); // limpiar error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Apuesta inválida. Intenta de nuevo.\n";
        } else {
            break;
        }
    }

    setApuesta(cantidad);
    setDinero(dinero - cantidad);
    std::cout << "Has apostado $" << cantidad << ". Suerte!" << std::endl;

    return apuestaActual;
}

// ======== Juego de cartas ========

void Jugador::recibirCarta(const Carta& carta) {
    mano.agregarCarta(carta);
}

int Jugador::calcularMano() const {
    return mano.calcularValor();
}

bool Jugador::tieneBlackjack() const {
    return mano.tieneBlackjack();
}

bool Jugador::seHaPasado() const {
    return mano.seHaPasado();
}

void Jugador::mostrarMano() const {
    std::cout << "\n" << nombre << " tiene:\n";
    mano.mostrar();
}

void Jugador::limpiarMano() {
    mano.limpiar();
}

// ======== Info básica ========

std::string Jugador::getNombre() const {
    return nombre;
}

#include "Jugador.h"
#include <iostream>

bool Jugador::quiereCarta() const {
    char respuesta;
    std::cout << nombre << ", ¿quieres otra carta? (s/n): ";
    std::cin >> respuesta;
    return respuesta == 's' || respuesta == 'S';
}

Jugador::~Jugador() {
    // Destructor vacío pero necesario si hay métodos virtuales
}
