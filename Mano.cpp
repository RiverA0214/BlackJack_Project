#include "Mano.h"
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