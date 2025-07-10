#include "Crupier.h"
// Crea un crupier con nombre fijo y "dinero infinito"
    Crupier();
    
    // Muestra solo la primera carta (oculta el resto)
    void mostrarManoInicial() const;
    
    // Decide si el crupier debe pedir otra carta
    bool quiereCarta() const override;