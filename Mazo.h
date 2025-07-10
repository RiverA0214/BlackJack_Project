/*
  Clase Mazo
  Representa el mazo de cartas completo para el juego
  
  Esta clase es utilizada por:
  - Juego (composición: el juego contiene el mazo)
  
  Relaciones:
  - Composición con Carta (contiene todas las cartas del juego)
  
  Responsabilidades:
  - Crear y almacenar las 52 cartas del juego
  - Barajar las cartas para orden aleatorio
  - Repartir cartas a los jugadores
  - Informar cartas restantes
*/
#ifndef MAZO_H
#define MAZO_H

#include <vector>
#include "Carta.h"

class Mazo {
private:
    std::vector<Carta> cartas;
    
public:
    // Constructor que crea un mazo completo de 52 cartas
    Mazo();
    
    // Mezcla las cartas en orden aleatorio
    void barajar();
    
    // Reparte la última carta del mazo
    Carta repartir();
    
    // Retorna número de cartas disponibles en el mazo
    int cartasRestantes() const;
};

#endif
