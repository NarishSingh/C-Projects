/*
 * File:   main.cpp
 * Author: naris
 *
 * Created on August 7, 2020, 10:47 AM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <limits>
#include <math.h>
using std::cout, std::cin, std::vector, std::string;
#define DICE_NUMS 6

/*dice functions*/

/**
 * Roll one die
 * @return {int} roll total, 1-6
 */
int roll()
{
    return floor(rand() % DICE_NUMS) + 1;
    return roll;
}

/**
 * Roll one die multiple times
 * @param throws {int} number of rolls
 * @return {vector} all roll results, each being 1-6
 */
vector<int> roll(int diceThrows)
{
    vector<int> rolls;

    for (int i = 0; i < diceThrows; i++)
    {
        rolls.push_back(roll());
    }

    return rolls;
}

/**
 * Roll multiple dice
 * @param numDice {int} amount of dice to roll, >=1
 * @return {int} roll total, range of (1 * # of dice) to (6 * # of dice)
 */
int rollDice(int numDice)
{
    int roll = floor((rand() % (DICE_NUMS * numDice))) + numDice;
    return roll;
}

/**
 * Roll many dice multiple times
 * @param numDice {int} number of dice to roll
 * @param diceThrows {int} number of rolls
 * @return {vector} results of all rolls
 */
vector<int> rollDice(int numDice, int diceThrows)
{
    vector<int> rolls;

    for (int i = 0; i < diceThrows; i++)
    {
        rolls.push_back(rollDice(numDice));
    }

    return rolls;
}

/*num input validation*/

/**
 * Get a numeric input >0 from user
 * @param value {int} value to set from input
 * @param prompt {string} prompt to display to user
 * @return {int} set value arg to input and return
 */
int getNumInput(int value, string prompt)
{
    cout << prompt;
    while (!(cin >> value))
    {
        if (cin.fail())
        {
            cout << "Numeric entry required." << '\n';
            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    }

    return value;
}

/**
 * Get a numeric input >0 from user
 * @param value {int} value to set from input
 * @param minLimit {int} the minimum value for input
 * @param prompt {string} prompt to display to user
 * @return {int} set value arg to input and return
 */
int getNumInput(int value, int minLimit, string prompt)
{
    do
    {
        cout << prompt;
        while (!(cin >> value))
        {
            if (cin.fail())
            {
                cout << "Numeric entry required." << '\n';
            }

            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while (value < minLimit);

    return value;
}

/**
 * Get a numeric input >0 from user
 * @param value {int} value to set from input
 * @param minLimit {int} the minimum value for input
 * @param maxLimit {int} the maximum value for input
 * @param prompt {string} prompt to display to user
 * @return {int} set value arg to input and return
 */
int getNumInput(int value, int minLimit, int maxLimit, string prompt)
{
    do
    {
        cout << prompt;
        while (!(cin >> value))
        {
            if (cin.fail())
            {
                cout << "Numeric entry required." << '\n';
            }

            cin.clear();
            cin.ignore(std::numeric_limits<int>::max(), '\n');
        }
    } while (value < minLimit || value > maxLimit);

    return value;
}

int main(int argc, char **argv)
{
    const int minInput = 1;
    srand(time(0));

    cout << "===Dice===" << '\n';
    int diceAmount = getNumInput(diceAmount, minInput, "Please enter number of dice: ");
    // FIXME this stat array is crashing for larger combinations
    int statArrSize = (diceAmount * DICE_NUMS) + 1;
    int stats[statArrSize] = {0}; // incr to account for 0

    int diceThrows = getNumInput(diceThrows, minInput, "Please enter number of dice throws: ");

    switch (diceAmount)
    {
    case 1:
    {
        if (diceThrows == 1)
        {
            cout << "You rolled " << roll();
        }
        else
        {
            cout << "Rolls:" << '\n';
            vector<int> results = roll(diceThrows);

            for (auto roll : results)
            {
                cout << roll << '\n';
                stats[roll]++;
            }

            cout << "Results: " << '\n';
            for (int i = 1; i < DICE_NUMS; i++)
            {
                cout << i << ": " << stats[i] << '\n';
            }
        }

        break;
    }
    default:
    {
        if (diceThrows == 1)
        {
            cout << "You rolled " << rollDice(diceAmount);
        }
        else
        {
            cout << "Rolls:" << '\n';
            vector<int> results = rollDice(diceAmount, diceThrows);

            for (auto roll : results)
            {
                cout << roll << '\n';
                stats[roll]++;
            }

            cout << "Results: " << '\n';
            for (int i = diceAmount; i < statArrSize; i++)
            {
                cout << i << ": " << stats[i] << '\n';
            }
        }

        break;
    }
    }

    return 0;
}
