#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void greeting()
{
    cout << "Welcome in out Rock, Paper, Scissors game" << endl;
    cout << "Write rock, paper or scissors to start playing and @ to exit \n"
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

int moves()
{
    int playerMove = rand() % 3;
    int aiMove = rand() % 3;

    if (playerMove > aiMove)
        return 0;
    if (aiMove > playerMove)
        return 1;
    if (playerMove == aiMove)
        return 2;
}

void scoreCounter(int &playerScore, int &aiScore, string move, int points)
{
    if (isCorrectName(move))
    {
        if (points == 0)
        {
            playerScore++;

            cout << "Player: " << playerScore;
            cout << " AI: " << aiScore << endl;
        }
        if (points == 1)
        {
            aiScore++;

            cout << "Player: " << playerScore;
            cout << " AI: " << aiScore << endl;
        }
        if (points == 2)
        {
            playerScore++;
            aiScore++;

            cout << "Player: " << playerScore;
            cout << " AI: " << aiScore << endl;
        }
    }
}

void gameplay(string move, int points)
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
            int points = moves();
            gameplay(move, points);
            scoreCounter(playerScore, aiScore, move, points);

            cout << endl;
        }
    }
    return 0;
}
