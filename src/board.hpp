#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>

class Board {
private:
    // Representação do tabuleiro como array unidimensional de 9 elementos
    // Cada posição pode conter ' ' (vazio), 'X' (jogador) ou 'O' (computador)
    char cells[9];
    
public:
    // Construtor - inicializa o tabuleiro vazio
    Board();
    
    // Retorna uma cópia do tabuleiro
    Board clone() const;
    
    // Retorna o conteúdo de uma célula específica
    char getCell(int position) const;
    
    // Realiza um movimento no tabuleiro
    void makeMove(int position, char player);
    
    // Desfaz um movimento
    void undoMove(int position);
    
    // Verifica se uma posição está vazia
    bool isMoveValid(int position) const;
    
    // Obtém lista de movimentos válidos (posições vazias)
    std::vector<int> getValidMoves() const;
    
    // Verifica se o jogo acabou (vitória ou empate)
    bool isGameOver() const;
    
    // Verifica se um jogador ganhou
    bool checkWin(char player) const;
    
    // Verifica se o jogo terminou em empate
    bool isDraw() const;
    
    // Avalia o estado do tabuleiro para o algoritmo minimax
    // Retorna valores positivos para vantagem do 'O', negativos para 'X'
    int evaluate() const;
    
    // Exibe o tabuleiro no console
    void display() const;
};

#endif // BOARD_HPP