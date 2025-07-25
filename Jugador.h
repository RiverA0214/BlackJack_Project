/*
  Clase Jugador
  Representa un jugador en el juego de blackjack
  
  Esta clase es heredada por:
  - Crupier (pq el crupier es un tipo especial de jugador)
  
  Relaciones:
  - Composición con Mano (cada jugador tiene su propia mano)
  
  Responsabilidades:
  - Tomar decisiones durante el juego (pedir/plantarse)
  - Gestionar su mano de cartas
  - Mantener su balance de dinero
  - Mostrar su estado durante el juego
*/
#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
#include "Mano.h"

class Jugador {
private:
    std::string nombre;
    double dinero;
    double apuestaActual;
    Mano mano;

public:

    // Constructor
    Jugador(const std::string& nombre, double dineroInicial);

    virtual ~Jugador();  //destructor virtual

    // Información del jugador
    std::string getNombre() const;
    
    // Apuesta y dinero
    void setApuesta(double apuesta);
    double getApuesta() const;
    
    void setDinero(double nuevoSaldo);       // asigna directamente
    void sumarDinero(double cantidad);       // suma ganancias
    double getDinero() const;

    // Lógica de apuestas
    double apuesta(); // solicita y procesa apuesta del jugador

    // Lógica del juego
    virtual bool quiereCarta() const;

    void recibirCarta(const Carta& carta);
    int calcularMano() const;
    bool tieneBlackjack() const;
    bool seHaPasado() const;

    void mostrarMano() const;
    void limpiarMano();
};

#endif
