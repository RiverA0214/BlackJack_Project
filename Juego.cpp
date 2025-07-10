#include "Juego.h"
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