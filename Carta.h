/*
  Clase Carta
  Representa una carta individual del juego con su valor 
  
  Esta clase es utilizada por:
  - Mazo (composición: el mazo contiene las cartas)
  - Mano (agregación: las manos contienen referencias a cartas)
  
  Responsabilidades:
  - Almacenar el palo y valor de la carta
  - Proporcionar métodos para acceder a sus atributos
  - Mostrar la representación visual de la carta
 */
#ifndef CARTA_H
#define CARTA_H

#include <string>

class Carta {
private:
    std::string palo;
    std::string valor;
    int valorNumerico;
    
public:
   
    //Constructor que crea una carta específica
    Carta(std::string palo, std::string valor, int valorNumerico);
    
    /// retorna  Palo de la carta
    std::string getPalo() const;
    
    /// retorna  Valor nominal de la carta (ej. "A", "K")
    std::string getValor() const;
    
    /// retorna Valor numérico según reglas del blackjack
    int getValorNumerico() const;
    
    /// Muestra la carta en formato "valor de palo"
    void mostrar() const;
};
#endif
