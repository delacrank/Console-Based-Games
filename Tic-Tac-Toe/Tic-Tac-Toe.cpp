#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const char x = 'x';
const char o = 'o';
const char empty = ' ';
const char tie = 't';
const char no_one = 'n';

void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(const vector<char>& board, char human);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);
void announceWinner(char winner, char computer, char human);

int main()
{
    int move;
    const int NUM_SQUARES = 9;
    vector<char> board(NUM_SQUARES, empty);
    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char turn = x;
    displayBoard(board);
    
    while(winner(board) == no_one)
    {
        if(turn == human)
        {
            move = humanMove(board, human);
            board[move] = human;
        }
        else
        {
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        turn = opponent(turn);
    }
    
    announceWinner(winner(board), computer, human);
    
    return 0;
}

void instructions()
{
    cout << "Welcome to tic-tac-toe\n";
    cout << "Make your move using the numbers 0 - 8\n";
    cout << "0 | 1 | 2\n";
    cout << "---------\n";
    cout << "3 | 4 | 5\n";
    cout << "---------\n";
    cout << "6 | 7 | 8\n";

    cout << "get ready\n\n";
}

char askYesNo(string question)
{
    char response;
    do
    {
        cout << question << " y\n ";
        cin >> response;
    } while(response != 'y' && response != 'n');
    
    return response;
}

int askNumber(string question, int high, int low)
{
    int number;
    do
    {
        cout << question << " (" << low << " - " << high << "): ";
        cin >> number;
    } while(number > high || number < low);
    
    return number;
}

char humanPiece()
{
    char go_first = askYesNo("Do you require the first move?");
    if(go_first = 'y')
    {
        cout << "\nThen take the first move\n";
        return x;
    }
    else 
    {
        cout << "I will go first" << endl;
        return o;
    }
}

char opponent(char piece)
{
    if(piece == x)
    {
        return o;
    }
    else
    {
        return x;
    }
}

void displayBoard(const vector<char>& board)
{
    cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
    cout << "\n\t" << "---------";
    cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
    cout << "\n\n";
}

char winner(const vector<char>& board)
{
    const int winning_rows[8][3] = { {0,1,2},
                                     {3,4,5},
                                     {6,7,8},
                                     {0,3,6},
                                     {1,4,7},
                                     {2,5,8},
                                     {0,4,8},
                                     {2,4,6} };
    const int total_rows = 8;
    
    for(int row = 0; row < total_rows; ++row)
    {
        if( (board[winning_rows[row][0]] != empty) && 
            (board[winning_rows[row][0]] == board[winning_rows[row][1]]) && 
            (board[winning_rows[row][1]] == board[winning_rows[row][2]]) )
           {
               return board[winning_rows[row][0]];
           }
    }
    
    if( count(board.begin(), board.end(), empty) == 0 )
        return tie;
    
    return no_one;
}

inline bool isLegal(int move, const vector<char>& board)
{
    return (board[move] == empty);
}

int humanMove(const vector<char>& board, char human)
{
    int move = askNumber("Where will you move?", (board.size() - 1));
    while(!isLegal(move, board))
    {
        cout << "\nThat square is already occupied\n";
        move = askNumber("Where will you move?", (board.size() - 1));
    }
    cout << "Fine\n";
    
    return move;
}

int computerMove(vector<char> board, char computer)
{
    unsigned int move = 0;
    bool found = false;
    
    while(!found && move < board.size())
    {
        if(isLegal(move, board))
        {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = empty;
        }
        
        if(!found)
        {
            ++move;
        }
    }
    
    if(!found)
    {
        move = 0;
        char human = opponent(computer);
        
        while(!found && move < board.size())
        {
            if(isLegal(move, board))
            {
                board[move] = human;
                found = winner(board) == human;
                board[move] = empty;
            }
            
            if(!found)
            {
                ++move;
            }
        }
    }
    
    if(!found)
    {
        move = 0;
        unsigned int i = 0;
        
        const int best_moves[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        
        while(!found && i < board.size())
        {
            move = best_moves[i];
            if(isLegal(move, board))
            {
                found = true;
            }
            
            ++i;
        }
    }
    
    cout << "I shall take square number " << move << endl;
    return move;
}

void announceWinner(char winner, char computer, char human)
{
    if(winner == computer)
    {
        cout << winner << "'s won\n";
    }
    
    else if(winner == human)
    {
        cout << winner << "'s won\n";   
    }
    
    else
    {
        cout << "its a tie";    
    }
}
