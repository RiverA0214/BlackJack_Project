#include "Jugador.h"
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
    
    // Retorna nombre del jugador
    std::string getNombre() const;