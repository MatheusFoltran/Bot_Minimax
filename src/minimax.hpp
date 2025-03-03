#ifndef MINIMAX_HPP
#define MINIMAX_HPP

#include "board.hpp"

class Minimax {
private:
    // Método recursivo que implementa o algoritmo minimax com poda alpha-beta
    // depth: profundidade atual na árvore de busca
    // isMaximizing: true se for o turno do maximizador (IA), false para o minimizador (humano)
    // alpha, beta: parâmetros para a poda alpha-beta
    int minimax(Board& board, int depth, bool isMaximizing, int alpha, int beta);

public:
    // Construtor padrão
    Minimax() = default;
    
    // Obtém o melhor movimento para o jogador atual
    // Retorna o índice (0-8) do melhor movimento
    int getBestMove(const Board& board, char player);
};

#endif // MINIMAX_HPP