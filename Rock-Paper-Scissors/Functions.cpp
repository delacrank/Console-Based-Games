#include "Functions.h"

int life = 3;

int CompAI()
{
    int i = 3;
    int x = 0;
    x = 1 + (rand() % i);
    return x;
}

int gameover()
{
    cout << "Game over" << endl;
    return 0;
}

void info()
{
    cout << "Input a number: " << endl;
    cout << "1 for Scissors" << endl;
    cout << "2 for Paper" << endl;
    cout << "3 for Rock" << endl;
}

void selection()
{

    char c;
   while((c = getchar()))
   {
       if(c == EOF || c == '\n')
           break;
        switch(c) {
            case '1':
                scissors();
                break;
            case '2':
                paper();
                break;
            case '3':
                rock();
                break;
            default:
                default1();
                break;
        }
   }
}

void rock()
{
    switch(CompAI()) {
        case 1:
            cout << "Computer AI has selected: " << 1 << endl;
            cout << "Rock beats scissors" << endl;
            ++life;
            cout << "Gain a life, lives left: " << life << endl;
            cout << endl;
            check();
            break;
        case 2:
            cout << "Computer AI has selected: " << 2 << endl;
            cout << "Paper beats rock" << endl;
            --life;
            cout << "Lose a life, lives left: " << life << endl;
            cout << endl;
            check();
            break;
        case 3:
            cout << "Computer AI has selected: " << 3 << endl;
            cout << "Rock cancels out rock, try again" << endl;
            cout << endl;
            check();
            break;
        default:
            default1();
            break;
    }
}

void paper()
{
    switch(CompAI()) {
        case 1:
            cout << "Computer AI has selected: " << 1 << endl;
            cout << "Scissors beats paper" << endl;
            --life;
            cout << "Lose a life, lives left: " << life << endl;
            cout << endl;
            check();
            break;
        case 2:
            cout << "Computer AI has selected: " << 2 << endl;
            cout << "Paper cancels out paper, try again" << endl;
            cout << endl;
            check();
            break;   
        case 3:
            cout << "Computer AI has selected: " << 3 << endl;
            cout << "Paper beats rock." << endl;
            ++life;
            cout << "Gain a life, lives left: " <<  life << endl;
            cout << endl;
            check();
            break;
        default:
            default1();
    }
} 

void scissors()
{
    switch(CompAI()) {
        case 1:
            cout << "Computer AI has selected: " << 1 << endl;
            cout << "Scissors cancels out scissors, try again.\n" << endl;
            cout << endl;
            check();
            break;
        case 2:
            cout << "Computer AI has selected: " << 2 << endl;
            cout << "Scissors beats paper." << endl;
            ++life;
            cout << "Gain a life, lives left: " <<  life << endl;
            cout << endl;
            check();
            break;
        case 3:
            cout << "Computer AI has selected: " << 3 << endl;
            cout << "Rock beats scissors" << endl;
            --life;
            cout << "Lose a life, lives left: " <<  life << endl;
            cout << endl;
            check();
            break;
        default:
            default1();
    }
}

void default1()
{
    cout << "Error, incorrect input, try again." << endl;
    cout << endl;
    info();
    selection();
}

void check()
{
    if(life < 0)
    {
        gameover();
    }
    else
    {
        info();
        selection();  
    }
}
