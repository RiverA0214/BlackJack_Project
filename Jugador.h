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
protected:
    std::string nombre;
    Mano mano;
    double dinero;
    
public:
    // Crea un nuevo jugador
    Jugador(std::string nombre, double dineroInicial);
    
    // Recibe una carta en su mano
    void recibirCarta(const Carta& carta);
    
    // Retorna valor total de la mano
    int calcularMano() const;
    
    // Muestra la mano del jugador
    void mostrarMano(bool mostrarTodas = true) const;
    
    // Retorna true si quiere otra carta
    virtual bool quiereCarta() const;
    
    // Retorna true si tiene blackjack
    bool tieneBlackjack() const;
    
    // Retorna true si se pasó de 21
    bool seHaPasado() const;
    
    // Prepara la mano para nueva ronda
    void limpiarMano();
    //
    double getDinero(){return dinero;}
    //Genera una apuesta por mano
    double apuesta();

    // Retorna nombre del jugador
    std::string getNombre() const;
};

#endif
