#include "Mazo.h"
 // Constructor que crea un mazo completo de 52 cartas
    Mazo();
    
    // Mezcla las cartas en orden aleatorio
    void barajar();
    
    // Reparte la última carta del mazo
    Carta repartir();
    
    // Retorna número de cartas disponibles en el mazo
    int cartasRestantes() const;