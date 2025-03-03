#ifndef GAME_HPP
#define GAME_HPP

#include "board.hpp"

// Definição de constantes para os jogadores
constexpr char PLAYER_HUMAN = 'X';
constexpr char PLAYER_AI = 'O';
constexpr char EMPTY_CELL = ' ';

class Game {
private:
    Board board;        // Tabuleiro do jogo
    char currentPlayer; // Jogador atual ('X' para humano, 'O' para AI)
    bool gameOver;      // Flag para controlar se o jogo acabou
    
    // Processa o turno do jogador humano
    void playerTurn();
    
    // Processa o turno da IA
    void aiTurn();
    
    // Exibe mensagem do resultado do jogo
    void displayResult() const;

public:
    // Construtor - inicializa o jogo
    Game();
    
    // Inicia o loop principal do jogo
    void run();
    
    // Verifica se o jogo acabou
    bool isGameOver() const;
    
    // Retorna o jogador atual
    char getCurrentPlayer() const;
    
    // Alterna o jogador atual
    void switchPlayer();
    
    // Obtém o tabuleiro atual
    const Board& getBoard() const;
};

#endif // GAME_HPP