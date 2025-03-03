#include "game.hpp"
#include "interface.hpp"
#include <iostream>
#include <cstdlib> // Para system()
#include <ctime>   // Para time() na inicialização da semente aleatória

int main() {
    // Inicializa a semente para geração de números aleatórios
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // Limpa a tela do console
    system("clear");
    
    // Exibe a mensagem de início do jogo
    Interface interface;
    interface.inicio();
    
    // Limpa a tela antes de iniciar o jogo
    system("clear");
    
    // Cria e executa o jogo
    Game game;
    game.run();
    
    // Mensagem final após o término do jogo
    
    interface.fim();
    
    return 0;
}