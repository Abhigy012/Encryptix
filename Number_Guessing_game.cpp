#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Instructions()
{
    cout << "******** Number Guessing Game ********" << "\n";
    cout << "\n";
    cout << " Levels : \n";
    cout << "          1. Number between 1-50 to be guessed in 5 attempts \n";
    cout << "          2. Number between 1-100 to be guessed in 10 attempts \n";
    cout << "          3. Number between 1-200 to be guessed in 15 attempts \n";
    cout << "\n";
}

void game(int level, int highscore[3])
{
    int range, attempts;
    if (level == 1)
    {
        range = 50;
        attempts = 5;
        if (highscore[0] == 0)
        {
            cout << "Level 1 \n";
        }
        else
        {
            cout << "Level 1, highscore: " << highscore[0] << " attempts\n";
        }
    }
    else if (level == 2)
    {
        range = 100;
        attempts = 10;
        if (highscore[1] == 0)
        {
            cout << "Level 2 \n";
        }
        else
        {
            cout << "Level 2, highscore: " << highscore[1] << " attempts\n";
        }
    }
    else if (level == 3)
    {
        range = 200;
        attempts = 15;
        if (highscore[2] == 0)
        {
            cout << "Level 3 \n";
        }
        else
        {
            cout << "Level 3, highscore: " << highscore[2] << " attempts\n";
        }
    }
    else
    {
        cout << "Invalid level!\n";
        return;
    }

    srand(time(0));
    int gen = rand() % range + 1;
    int guess;
    int i;
    for (i = 1; i <= attempts; i++)
    {
        cout << attempts - i + 1 << " attempts remaining, Guess the number: ";
        cin >> guess;
        if (guess < gen)
        {
            cout << " Too low! , Try Again \n";
        }
        else if (guess > gen)
        {
            cout << " Too High , Try Again \n";
        }
        else
        {
            cout << "That's right, you have guessed the correct number in " << i << " attempts \n";
            if (highscore[level - 1] == 0 || i < highscore[level - 1])
            {
                highscore[level - 1] = i;
            }
            break;
        }
    }
    if (i > attempts)
    {
        cout << "Sorry, you were not able to clear the level \n";
    }

    int choice;
    cout << "Do you want to play again? (1 for yes and 0 for no) \n";
    cin >> choice;
    while (choice != 1 && choice != 0)
    {
        cout << "Invalid choice. Please Try Again! (1 for yes and 0 for no)\n";
        cin >> choice;
    }
    if (choice)
    {
        cout << "Enter difficulty level: ";
        cin >> level;
        game(level, highscore);
    }
    else
    {
        cout << "No problem, see you again next time\n";
    }
}

int main()
{
    Instructions();
    int level;
    int highscore[3] = {0, 0, 0}; // High scores for levels 1, 2, and 3
    cout << "Enter difficulty level: ";
    cin >> level;
    if (level >= 1 && level <= 3)
    {
        game(level, highscore);
    }
    else
    {
        cout << "Oops! Invalid difficulty level entered\n";
    }
    return 0;
}
