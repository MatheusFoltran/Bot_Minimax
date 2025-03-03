#include "minimax.hpp"
#include <algorithm> // Para std::max e std::min
#include <climits>   // Para INT_MIN e INT_MAX

int Minimax::minimax(Board& board, int depth, bool isMaximizing, int alpha, int beta) {
    // Condição de parada: verifica se o jogo acabou ou atingiu profundidade máxima
    if (board.isGameOver() || depth == 0) {
        return board.evaluate();
    }
    
    // Obtém todos os movimentos possíveis
    std::vector<int> validMoves = board.getValidMoves();
    
    if (isMaximizing) {
        // Turno do maximizador (IA - 'O')
        int bestScore = INT_MIN;
        
        for (int move : validMoves) {
            // Faz o movimento
            board.makeMove(move, 'O');
            
            // Chama recursivamente o minimax para o oponente
            int score = minimax(board, depth - 1, false, alpha, beta);
            
            // Desfaz o movimento para explorar outras possibilidades
            board.undoMove(move);
            
            // Atualiza o melhor score
            bestScore = std::max(score, bestScore);
            
            // Poda Alpha-Beta
            alpha = std::max(alpha, bestScore);
            if (beta <= alpha) {
                break; // Corte Beta
            }
        }
        
        return bestScore;
    } 
    else {
        // Turno do minimizador (Humano - 'X')
        int bestScore = INT_MAX;
        
        for (int move : validMoves) {
            // Faz o movimento
            board.makeMove(move, 'X');
            
            // Chama recursivamente o minimax para o oponente
            int score = minimax(board, depth - 1, true, alpha, beta);
            
            // Desfaz o movimento para explorar outras possibilidades
            board.undoMove(move);
            
            // Atualiza o melhor score
            bestScore = std::min(score, bestScore);
            
            // Poda Alpha-Beta
            beta = std::min(beta, bestScore);
            if (beta <= alpha) {
                break; // Corte Alpha
            }
        }
        
        return bestScore;
    }
}

int Minimax::getBestMove(const Board& board, char player) {
    // Cria uma cópia do tabuleiro para não modificar o original
    Board boardCopy = board;
    
    // Obtém todos os movimentos possíveis
    std::vector<int> validMoves = boardCopy.getValidMoves();
    
    int bestScore = (player == 'O') ? INT_MIN : INT_MAX;
    int bestMove = -1; // Movimento inválido como valor padrão
    
    // Para cada movimento possível
    for (int move : validMoves) {
        // Faz o movimento
        boardCopy.makeMove(move, player);
        
        // Chama o minimax para avaliar o movimento
        int score;
        if (player == 'O') { // IA - maximizador
            score = minimax(boardCopy, 9, false, INT_MIN, INT_MAX); // profundidade máxima = 9 (total de casas)
            
            if (score > bestScore) {
                bestScore = score;
                bestMove = move;
            }
        } 
        else { // Humano - minimizador
            score = minimax(boardCopy, 9, true, INT_MIN, INT_MAX);
            
            if (score < bestScore) {
                bestScore = score;
                bestMove = move;
            }
        }
        
        // Desfaz o movimento
        boardCopy.undoMove(move);
    }
    
    // Se nenhum movimento for encontrado (não deve acontecer), retorna o primeiro movimento válido
    if (bestMove == -1 && !validMoves.empty()) {
        bestMove = validMoves[0];
    }
    
    return bestMove;
}