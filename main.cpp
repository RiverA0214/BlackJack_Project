#include "Juego.h"
#include <iostream>
int main() {
    //int cantidadJugadores;
    //std::cout<<"Ingrese la cantida de jugadores: ";
    //std::cin>>cantidadJugadores;
    //std::cout<<cantidadJugadores;
        

    Juego juego(2); // Puedes cambiar el número de jugadores
    char opcion;

    do {
        juego.iniciarRonda();
        std::cout << "\n¿Jugar otra ronda? (s/n): ";
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar newline
    } while (opcion == 's' || opcion == 'S');

    return 0;
}
