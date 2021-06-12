#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void modeSelection()
{
    cout << "Select a mode: \n"
         << "1. Infinite mode. \n"
         << "2. Rounds mode. \n"
         << endl;
}

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

void printWinner(int &playerScore, int &aiScore)
{
    if (playerScore > aiScore)
    {
        cout << "Player won!" << endl;
    }
    else if (aiScore > playerScore)
    {
        cout << "AI won!" << endl;
    }
    else
    {
        cout << "Draw!" << endl;
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

void result(string move, int winState)
{

    if (isCorrectName(move))
    {
        if (winState == 0)
            cout << "Player wins \n";
        if (winState == 1)
            cout << "AI wins \n";
        if (winState == 2)
            cout << "Draw \n";
    }
    else
        cout << "Wrong move \n";
}

void infiniteMode(int &playerScore, int &aiScore, string move, int winState)
{
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
            winState = drawState();
            printMoves(move, winState);
            result(move, winState);
            scoreCounter(playerScore, aiScore, move, winState);
            cout << endl;
        }
    }
}

void roundsMode(int &playerScore, int &aiScore, string move, int winState)
{
    int roundsLimit;
    cout << "How many rounds do you want to play?"
         << endl;
    cin >> roundsLimit;
    int roundCounter = 1;

    while (roundCounter != roundsLimit + 1)
    {
        cout << "Round " << roundCounter << endl;
        cout << "\nMake a move" << endl;
        cin >> move;

        if (move == "@")
        {
            break;
        }
        else
        {
            if (isCorrectName(move))
                roundCounter++;
            winState = drawState();
            printMoves(move, winState);
            result(move, winState);
            scoreCounter(playerScore, aiScore, move, winState);
            cout << endl;
        }
    }
    if (roundCounter == roundsLimit + 1)
    {
        cout << "End of round. " << endl;
        printWinner(playerScore, aiScore);
    }
}

void selectMode(int &playerScore, int &aiScore, string move, int winState)
{
    int mode;
    modeSelection();
    cin >> mode;

    switch (mode)
    {
    case 1:
    {
        cout << "You selected infinite mode." << endl;
        infiniteMode(playerScore, aiScore, move, winState);
        break;
    }
    case 2:
    {
        cout << "\nYou selected rounds mode." << endl;
        roundsMode(playerScore, aiScore, move, winState);
        break;
    }
    default:
    {
        cout << "No such mode found." << endl;
        break;
    }
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int aiScore = 0;
    int playerScore = 0;
    int winState = drawState();
    string move;

    greeting();
    selectMode(playerScore, aiScore, move, winState);

    return 0;
}
