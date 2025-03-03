#include "interface.hpp"
#include <iostream>

Interface::Interface() {
    // Construtor vazio (corrigido para 'I' maiúsculo)
}

void Interface::inicio() {
    std::cout << "=== JOGO DA VELHA COM MINIMAX ===\n\n";
    std::cout << "Bem-vindo ao Jogo da Velha com IA usando o algoritmo Minimax!\n";
    std::cout << "Você joga como 'X' e o computador como 'O'.\n";
    std::cout << "Boa sorte! (Você vai precisar...)\n\n";
    std::cout << "Pressione Enter para começar...";
    std::cin.get(); // Limpa o buffer e espera o usuário pressionar Enter
}

void Interface::fim() {
    std::cout << "\nObrigado por jogar!\n";
    std::cout << "Pressione Enter para sair...";
    std::cin.get(); // Limpa o buffer e espera o usuário pressionar Enter
    std::cin.get(); // Pode precisar de um segundo cin.get() dependendo do fluxo do programa
}