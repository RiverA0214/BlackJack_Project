/*
  Clase Crupier
  Representa al crupier (dealer) en el juego de blackjack
  
  Esta clase hereda de:
  - Jugador (pq el crupier es un tipo especial de jugador)
  
  Responsabilidades adicionales:
  - Mostrar solo su primera carta inicialmente
  - Seguir las reglas automáticas del crupier (pedir hasta 17)
  - No participa en apuestas (usa dinero infinito virtual)
*/
#ifndef CRUPIER_H
#define CRUPIER_H

#include "Jugador.h"

class Crupier : public Jugador {
public:
    // Crea un crupier con nombre fijo y "dinero infinito"
    Crupier();
    
    // Muestra solo la primera carta (oculta el resto)
    void mostrarManoInicial() const;
    
    // Decide si el crupier debe pedir otra carta
    bool quiereCarta() const override;
};

#endif
