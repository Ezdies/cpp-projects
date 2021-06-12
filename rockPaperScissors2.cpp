#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void greeting()
{
    cout << "Welcome in out Rock, Paper, Scissors game." << endl;
    cout << "Write rock, paper or scissors to start playing and @ to exit. \n"
         << endl;
}

bool isCorrectName(string move)
{
    if (move == "rock" || move == "paper" || move == "scissors")
    {
        return true;
    }
    return false;
}

int drawState()
{
    int playerMove = rand() % 3;
    int aiMove = rand() % 3;

    if (playerMove > aiMove)
        return 0;
    if (aiMove > playerMove)
        return 1;
    if (playerMove == aiMove)
        return 2;

    return 0;
}

void printMoves(string move, int points)
{

    if (isCorrectName(move))
    {
        if (points == 0 && move == "rock")
        {
            cout << "Player plays rock" << endl;
            cout << "AI plays scissors" << endl;
        }
        if (points == 0 && move == "paper")
        {
            cout << "Player plays paper" << endl;
            cout << "AI plays rock" << endl;
        }
        if (points == 0 && move == "scissors")
        {
            cout << "Player plays scissors" << endl;
            cout << "AI plays paper" << endl;
        }
        if (points == 1 && move == "rock")
        {
            cout << "Player plays rock" << endl;
            cout << "AI plays paper" << endl;
        }
        if (points == 1 && move == "paper")
        {
            cout << "Player plays paper" << endl;
            cout << "AI plays scissors" << endl;
        }
        if (points == 1 && move == "scissors")
        {
            cout << "Player plays scissors" << endl;
            cout << "AI plays rock" << endl;
        }
        if (points == 2 && move == "rock")
        {
            cout << "Player plays rock" << endl;
            cout << "AI plays rock" << endl;
        }
        if (points == 2 && move == "paper")
        {
            cout << "Player plays paper" << endl;
            cout << "AI plays paper" << endl;
        }
        if (points == 2 && move == "scissors")
        {
            cout << "Player plays scissors" << endl;
            cout << "AI plays scissors" << endl;
        }
    }
}

void scoreCounter(int &playerScore, int &aiScore, string move, int points)
{
    if (isCorrectName(move))
    {
        if (points == 0) //player wins
        {
            cout << "Player: " << ++playerScore;
            cout << " AI: " << aiScore << endl;
        }
        if (points == 1) //ai wins
        {

            cout << "Player: " << playerScore;
            cout << " AI: " << ++aiScore << endl;
        }
        if (points == 2) //draw
        {
            cout << "Player: " << playerScore;
            cout << " AI: " << aiScore << endl;
        }
    }
}

void result(string move, int points)
{

    if (isCorrectName(move))
    {
        if (points == 0)
            cout << "Player wins \n";
        if (points == 1)
            cout << "AI wins \n";
        if (points == 2)
            cout << "Draw \n";
    }
    else
        cout << "Wrong move \n";
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int aiScore = 0;
    int playerScore = 0;

    string move;

    greeting();

    while (true)
    {
        cout << "Make a move" << endl;
        cin >> move;

        if (move == "@")
        {
            break;
        }
        else
        {
            int winState = drawState();
            printMoves(move, winState);
            result(move, winState);
            scoreCounter(playerScore, aiScore, move, winState);
            cout << endl;
        }
    }
    return 0;
}
