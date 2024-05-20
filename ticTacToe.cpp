#include <iostream>
#include <vector>

void boardPrinter();
void runGame();
bool isGameOver();
bool updateBoard();

std::vector<std::vector<int>> board{{2, 2, 2},
                                    {2, 2, 2},
                                    {2, 2, 2}};
bool takeTurns{1};
int x{};
int y{};
int turns{};
bool winner{};

int main(){
    std::cout << "Welcome to Tic Tac Toe!" << std::endl
    << "I hope you enjoy your stay with us." << std::endl << std::endl << std::endl;
    runGame();
    boardPrinter();
    std::cout << std::endl << std::endl;
    std::cout << "Looks like ";
    if(winner){
        if(takeTurns){
            std::cout << "player 2";
        }else{
            std::cout << "player 1";
        }
    }else{
        std::cout << "no one";
    }
    std::cout << " had the upper hand." << std::endl
    << "Until next time!" << std::endl;
    return 0;
}

void runGame(){
    while(!isGameOver()){
        boardPrinter();
        if(takeTurns){
            std::cout << "It is player 1's turn" << std::endl
            << "Please enter the x-coordinate: ";
            std::cin >> x;
            std::cout << "Now please enter the y-coordinate: ";
            std::cin >> y;
            takeTurns = 0;
        }else{
            std::cout << "It is player 2's turn" << std::endl
            << "Please enter the x-coordinate: ";
            std::cin >> x;
            std::cout << "Now please enter the y-coordinate: ";
            std::cin >> y;
            takeTurns = 1;
        }
        if(!updateBoard()){
            takeTurns = !takeTurns;
        }
    }
}

bool isGameOver(){
    int row{};
    int column{};
    int value{};
    while(row < 3){
        column = 0;
        value = board[row][column];
        if(value == 2){
            ++row;
            continue;
        }
        ++column;
        while(column < 3){
            if(value != board[row][column]){
                break;
            }
            ++column;
        }
        if(column == 3){
            winner = 1;
            return 1;
        }
        ++row;
    }
    row = 0;
    column = 0;
    while(column < 3){
        row = 0;
        value = board[row][column];
        if(value == 2){
            ++column;
            continue;
        }
        ++row;
        while(row < 3){
            if(value != board[row][column]){
                break;
            }
            ++row;
        }
        if(row == 3){
            winner = 1;
            return 1;
        }
        ++column;
    }
    value = board[0][0];
    if(value != 2 && value == board[1][1] && value == board[2][2]){
        winner = 1;
        return 1;
    }
    value = board[0][2];
    if(value != 2 && value == board[1][1] && value == board[2][0]){
        winner = 1;
        return 1;
    }
    if(turns == 9){
        winner = 0;
        return 1;
    }
    return 0;
}

void boardPrinter(){
    std::cout << std::endl << std::endl;
    int row{1};
    int column{1};
    std::cout << "  1 2 3" << std::endl;
    while(row <= 3){
        std::cout << row << "|";
        column = 1;
        while(column <= 3){
            if(board[row - 1][column - 1] == 0){
                std::cout << "O|";
            }else{
                if(board[row - 1][column - 1] == 1){
                    std::cout << "X|";
                }else{
                    std::cout << " |";
                }
            }
            ++column;
        }
        std::cout << std::endl;
        ++row;
    }
}

bool updateBoard(){
    if(board[y - 1][x - 1] == 0 || board[y - 1][x - 1] == 1){
        std::cout << "Something is already there, sorry!" << std::endl;
        return 0;
    }else{
        if(takeTurns){
            board[y - 1][x - 1] = 0;
        }else{
            board[y - 1][x - 1] = 1;
        }
        ++turns;
        return 1;
    }
}
