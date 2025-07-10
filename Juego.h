/*
  Clase Juego
  Clase principal que orquesta el juego completo
  
  Relaciones:
  - Composición con Mazo (el juego posee su mazo)
  - Composición con Jugador (el juego gestiona los jugadores)
  - Composición con Crupier (el juego tiene un crupier)
  
  Responsabilidades:
  - Gestionar el flujo completo del juego
  - Coordinar interacciones entre todos los componentes
  - Controlar las rondas de apuestas
  - Determinar ganadores y pagar premios
*/
#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "Jugador.h"
#include "Crupier.h"
#include "Mazo.h"

class Juego {
private:
    std::vector<Jugador> jugadores;
    Crupier crupier;
    Mazo mazo;
    
public:
    // Inicia un nuevo juego con jugadores
    Juego(int numJugadores);
    
    // Ejecuta una ronda completa del juego
    void iniciarRonda();
    
    // Reparte 2 cartas iniciales a cada participante
    void repartirCartasIniciales();
    
    // Gestiona los turnos de todos los jugadores
    void jugarTurnos();
    
    // Ejecuta el turno automático del crupier
    void turnoCrupier();
    
    // Compara manos y determina los ganadores
    void determinarGanadores();
    
    // Muestra los resultados finales de la ronda
    void mostrarResultados() const;
};

#endif
