/*************************************************************
 * Lottery Winner Checker                                    *
 *                                                           *
 * This program initializes an array with ten predefined     *
 * lottery ticket numbers. It allows the user to enter this  *
 * week's winning 5-digit number and performs a linear search*
 * to check if the number matches any of the player's tickets.*
 *                                                           *
 * If a match is found, the program announces the ticket     *
 * position as a winner; otherwise, it informs the player of *
 * the loss.                                                 *
 *                                                           *
 * Developed by: Nikita Baiborodov                           *
 *************************************************************/

#include <iostream>
using namespace std;

/*************************************************************
 * Function Prototypes                                       *
 *************************************************************/
int linearSearch(const int[], int, int); // Performs a linear search on the array

/*************************************************************
 * Main Function                                             *
 * Initializes lottery numbers and handles user input/output *
 *************************************************************/
int main() {

    /*************************************************************
     * Constants and Array Declaration                           *
     *************************************************************/
    const int SIZE = 10; // Total number of lottery tickets
    int luckyNumbers[SIZE] = { 13579, 26791, 26792, 33445, 55555,
                              62483, 77777, 79422, 85647, 93121 };

    int winningNumber, result;

    /*************************************************************
     * Input: Prompt user for this week's winning number         *
     *************************************************************/
    cout << "Enter this week's winning 5-digit lottery number: ";
    cin >> winningNumber;

    /*************************************************************
     * Search the array for the winning number                   *
     *************************************************************/
    result = linearSearch(luckyNumbers, SIZE, winningNumber);

    /*************************************************************
     * Output: Display the user's tickets and results            *
     *************************************************************/
    cout << "\nLottery Results:" << endl;
    cout << "----------------------------------" << endl;
    cout << "Your lottery ticket numbers: ";

    for (int i = 0; i < SIZE; i++) {
        cout << luckyNumbers[i] << " ";
    }

    cout << "\nEntered winning number: " << winningNumber << endl;

    if (result == -1) {
        cout << "Sorry, none of your tickets won this week." << endl;
    }
    else {
        cout << "Congratulations! Your ticket at position "
            << (result + 1) << " is a WINNER!" << endl;
    }

    /*************************************************************
     * Developer Signature                                       *
     *************************************************************/
    cout << "\nDeveloped by: Nikita Baiborodov" << endl;

    return 0;  // Indicate that the program ran successfully
}

/*************************************************************
 * linearSearch                                              *
 * This function performs a linear search on an array.       *
 * It searches for the given value in the array. If found,   *
 * it returns the index of the value. If not, it returns -1. *
 *************************************************************/
int linearSearch(const int arr[], int size, int value) {
    int index = 0;       // Subscript to search the array
    int position = -1;   // To record the position of the search value
    bool found = false;  // Flag to indicate if the value was found

    // Loop through the array until the value is found or end of array is reached
    while (index < size && !found) {
        if (arr[index] == value) {
            found = true;          // Set the flag
            position = index;      // Record the value's index (subscript)
        }
        index++;                   // Move to the next element in the array
    }
    return position;               // Return the position of the value or -1 if not found
}

