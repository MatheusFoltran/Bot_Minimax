#include "board.hpp"

Board::Board() {
    // Inicializa o tabuleiro vazio
    for (int i = 0; i < 9; i++) {
        cells[i] = ' ';
    }
}

Board Board::clone() const {
    // Cria uma cópia do tabuleiro
    Board copy;
    for (int i = 0; i < 9; i++) {
        copy.cells[i] = cells[i];
    }
    return copy;
}

char Board::getCell(int position) const {
    if (position >= 0 && position < 9) {
        return cells[position];
    }
    return '\0'; // Retorna caractere nulo para posição inválida
}

void Board::makeMove(int position, char player) {
    if (isMoveValid(position)) {
        cells[position] = player;
    }
}

void Board::undoMove(int position) {
    if (position >= 0 && position < 9) {
        cells[position] = ' ';
    }
}

bool Board::isMoveValid(int position) const {
    return position >= 0 && position < 9 && cells[position] == ' ';
}

std::vector<int> Board::getValidMoves() const {
    std::vector<int> moves;
    for (int i = 0; i < 9; i++) {
        if (cells[i] == ' ') {
            moves.push_back(i);
        }
    }
    return moves;
}

bool Board::isGameOver() const {
    return checkWin('X') || checkWin('O') || isDraw();
}

bool Board::checkWin(char player) const {
    // Verificação de linhas
    for (int i = 0; i < 3; i++) {
        if (cells[3*i] == player && cells[3*i+1] == player && cells[3*i+2] == player)
            return true;
    }
    
    // Verificação de colunas
    for (int i = 0; i < 3; i++) {
        if (cells[i] == player && cells[i+3] == player && cells[i+6] == player)
            return true;
    }
    
    // Verificação de diagonais
    if (cells[0] == player && cells[4] == player && cells[8] == player)
        return true;
    if (cells[2] == player && cells[4] == player && cells[6] == player)
        return true;
        
    return false;
}

bool Board::isDraw() const {
    // Se todas as células estão preenchidas e ninguém ganhou, é um empate
    if (!checkWin('X') && !checkWin('O')) {
        for (int i = 0; i < 9; i++) {
            if (cells[i] == ' ') {
                return false; // Ainda há movimentos possíveis
            }
        }
        return true; // Todas as células preenchidas, ninguém ganhou
    }
    return false;
}

int Board::evaluate() const {
    if (checkWin('O')) return 10;      // Computador ganhou
    else if (checkWin('X')) return -10; // Humano ganhou
    else return 0;                      // Empate ou jogo em andamento
}


void Board::display() const {
    std::cout << "\n";
    for (int i = 0; i < 3; i++) {
        std::cout << " ";
        
        // Primeiro caractere da linha
        if (cells[3*i] == ' ') 
            std::cout << i*3;
        else 
            std::cout << cells[3*i];
            
        std::cout << " | ";
        
        // Segundo caractere da linha
        if (cells[3*i+1] == ' ') 
            std::cout << i*3+1;
        else 
            std::cout << cells[3*i+1];
            
        std::cout << " | ";
        
        // Terceiro caractere da linha
        if (cells[3*i+2] == ' ') 
            std::cout << i*3+2;
        else 
            std::cout << cells[3*i+2];
            
        std::cout << " \n";
        
        // Linha separadora, exceto após a última linha
        if (i < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}