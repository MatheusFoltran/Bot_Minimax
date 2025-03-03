#include "game.hpp"
#include "minimax.hpp" // Inclui para usar o algoritmo minimax na IA
#include <iostream>
#include <limits>

Game::Game() : currentPlayer(PLAYER_HUMAN), gameOver(false) {
    // O construtor inicializa o jogo com o jogador humano começando
    // O tabuleiro é inicializado automaticamente pelo construtor de Board
}

void Game::run() {
    std::cout << "=== JOGO DA VELHA ===\n";
    std::cout << "Você é " << PLAYER_HUMAN << " e o computador é " << PLAYER_AI << ".\n";
    std::cout << "As posições do tabuleiro são numeradas de 0 a 8, como mostrado abaixo:\n";
    
    // Mostra o tabuleiro com posições numeradas
    board.display();
    
    // Loop principal do jogo
    while (!gameOver) {
        if (currentPlayer == PLAYER_HUMAN) {
            playerTurn();
        } else {
            aiTurn();
        }
        
        // Verifica se o jogo acabou após a jogada
        if (board.isGameOver()) {
            gameOver = true;
            displayResult();
        } else {
            // Se o jogo não acabou, alterna para o próximo jogador
            switchPlayer();
        }
    }
}

void Game::playerTurn() {
    int position;
    bool validMove = false;
    
    std::cout << "\nSua vez! Digite a posição (0-8): ";
    
    while (!validMove) {
        // Verifica se a entrada é um número inteiro
        if (!(std::cin >> position)) {
            std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta entrada inválida
            std::cout << "Entrada inválida. Digite um número entre 0 e 8: ";
            continue;
        }
        
        // Verifica se a posição é válida
        if (board.isMoveValid(position)) {
            validMove = true;
        } else {
            std::cout << "Movimento inválido. Escolha uma posição vazia (0-8): ";
        }
    }
    
    // Executa o movimento
    board.makeMove(position, PLAYER_HUMAN);
    std::cout << "Você escolheu a posição " << position << ".\n";
    board.display();
}

void Game::aiTurn() {
    std::cout << "\nVez do computador...\n";
    
    // Usa o algoritmo minimax para determinar o melhor movimento
    Minimax minimax;
    int bestMove = minimax.getBestMove(board, PLAYER_AI);
    
    // Executa o movimento
    board.makeMove(bestMove, PLAYER_AI);
    
    std::cout << "O computador escolheu a posição " << bestMove << ".\n";
    board.display();
}

void Game::displayResult() const {
    std::cout << "\n=== FIM DE JOGO ===\n";
    
    if (board.checkWin(PLAYER_HUMAN)) {
        std::cout << "Parabéns! Você venceu!\n";
    } else if (board.checkWin(PLAYER_AI)) {
        std::cout << "O computador venceu!\n";
    } else {
        std::cout << "Empate!\n";
    }
}

bool Game::isGameOver() const {
    return gameOver;
}

char Game::getCurrentPlayer() const {
    return currentPlayer;
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == PLAYER_HUMAN) ? PLAYER_AI : PLAYER_HUMAN;
}

const Board& Game::getBoard() const {
    return board;
}