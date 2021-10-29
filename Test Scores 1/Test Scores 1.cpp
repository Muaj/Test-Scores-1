// Test Scores 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//Function prototype
void selectionSort(int array[], int size);
int* getScores(int scores);
void averageScore(int array[], int size);


int main()
{
    int numberOfScores;
    cout << "How many test scores are going to be entered?" << endl;
    cin >> numberOfScores;
    getScores(numberOfScores);
    
}

int *getScores(int scores)
{
    int* scoreArray = nullptr;
    int testScore;

    if (scores <= 0) {
        return nullptr;
    }

    scoreArray = new int[scores];


    for (int i = 0; i < scores; i++)
    {
        cout << "Enter the score for test number " << i + 1 << ": " << endl;
        cin >> testScore;
        if (testScore > 0)
        {
            *(scoreArray + i) = testScore;
        }
        else
        {
            cout << "Error: Enter a value of 0 or higher." << endl;
            cin >> testScore;
        }
    }
    
    selectionSort(scoreArray, scores); //sort score array
    averageScore(scoreArray, scores); //calc average
    return scoreArray;
}


void selectionSort(int array[], int size)
{
    int minIndex, minValue;
    
    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = *(array + start);
        for (int index = start + 1; index < size; index++) {
            if (*(array + index) < minValue)
            {
                minValue = *(array + index);
                minIndex = index;
            }
        }
        swap(*(array + minIndex), *(array + start));
    }

    //print sorted array
    cout << "Here are the scores you entered: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << *(array + i) << " ";
    }

}

void averageScore(int array[], int size)
{
    int averageScore;
    int totalSum = 0;

    for (int i = 0; i < size; i++)
    {
        totalSum += *(array + i);
    }
    averageScore = (totalSum / size);
    
    cout << "\nThe average score for these tests is: " << averageScore << endl;
}
