/*
  Clase Mano
  Representa la mano de cartas de un jugador o crupier
  
  Esta clase es utilizada por:
  - Jugador (composición: cada jugador tiene una mano)
  - Crupier (herencia de Jugador)
  
  Relaciones:
  - Agregación con Carta (contiene referencias a cartas del mazo)
  
  Responsabilidades:
  - Almacenar cartas recibidas del mazo
  - Calcular el valor total según reglas del blackjack
  - Determinar si hay blackjack o se pasó de 21
  - Mostrar las cartas en la mano
*/
#ifndef MANO_H
#define MANO_H

#include <vector>
#include "Carta.h"

class Mano {
private:
    std::vector<Carta> cartas;
    
public:
    // Añade una carta a la mano
    void agregarCarta(const Carta& carta);
    
    // Calcula el valor óptimo de la mano
    int calcularValor() const;
    
    // Retorna true si la mano es blackjack (A + 10/figura)
    bool tieneBlackjack() const;
    
    // Retorna true si el valor > 21 (se pasó)
    bool seHaPasado() const;
    
    // Muestra todas las cartas en la mano
    void mostrar() const;
    
    // Vacía la mano para nueva ronda
    void limpiar();
};

#endif
