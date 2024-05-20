// 0521hw3_H1.43ฎ}บ๛งก
#include <stdio.h>
#include <stdlib.h>
// For using the rand() function
#include <time.h>
// For using the time() function
#include <ctype.h>
// To use the tolower() function from the <ctype.h> library
// (to convert uppercase to lowercase)
#include <conio.h>
// To use getch() and getche() for reading keyboard input

#define ROWS 9
#define COLS 9
// Define two constants and set both ROWS and COLS to 9,
// ensuring their values remain constant throughout the code

// Predefine the function prototypes
// The first letter of the function name should not be uppercase
int checkPassword();                                   // Check password
void chooseSeats(int seats[ROWS][COLS]);               // Choose seats
void showSeats(int seats[ROWS][COLS]);                 // Display booked seats
void initializeSeats(int seats[ROWS][COLS]);           // Initialize the seat map
void pressToContinue();                                // "Press any key to continue" for convenience
int exitConfirmation();                                // "Exit menu" functionality
void menu();                                           // Display the main menu for the first option
void notacceptSuggestedSeats(int seats[ROWS][COLS]);   // Reject suggested seats, cancel all chosen seats, prepare for reselection
int suggestSeats(int seats[ROWS][COLS], int numSeats); // Auto seat selection functionality
void acceptSuggestedSeats(int seats[ROWS][COLS]);      // Accept seats (after manual or auto selection, ask if user accepts)
int findFourSeats(int seats[ROWS][COLS]);
// Open the seat selection function after user clicks auto-select
// (because the logic for selecting four seats is different from general seat selection logic, mainly in the arrangement)

int main()
{
    int seats[ROWS][COLS]; // Set up a 9x9 seat map
    char choice; // Set 'choice' as the character input by the user after viewing the menu
    int keepRunning = 1; // See the comments in the switch function for case 'd'

    if (checkPassword()) // After entering the if-else function, immediately check if the password is correct. If correct, enter the main code
    {
        initializeSeats(seats); // Initialize the seat map
        do
        {
            menu(); // Display a personalized welcome screen
            fflush(stdin); // Clear the buffer, system("cls"); clears the screen
            scanf(" %c", &choice); // Read the user's menu selection
            choice = tolower(choice); 
            //0516 Need to look up the definition of tolower() function 
            //tolower() function converts uppercase letters to lowercase directly, so no need to write four more lines for 'case 'A'' in case
           
            switch (choice)
            {
                case 'a':
                    showSeats(seats);
                    pressToContinue();
                    system("cls"); // Clear screen and return to main menu
                    break;

                case 'b':
                    printf("\nHow many seats do you need (1-4)? ");
                    int numSeats;
                    fflush(stdin);
                    scanf("%d", &numSeats);
                    if (numSeats < 1 || numSeats > 4) // If the number of seats is out of range
                    {
                        printf("\nInput error, please enter a number between 1-4.\n");
                        pressToContinue();
                    }
                    else if (suggestSeats(seats, numSeats)) // If the number of seats is within range, execute the seat selection function
                    {
                        showSeats(seats);
                        printf("\nAre you satisfied with this seat arrangement (y/n)?: ");
                        char response; // Set a variable to store the user's input character for accepting the seats
                        fflush(stdin); // Clear the screen
                        scanf(" %c", &response);
                        if (tolower(response) == 'y') // If the user accepts the seat selection result
                        {
                            // If the user accepts the seat selection result, change the selected seats' symbol from "-" to "@"
                            acceptSuggestedSeats(seats); 
                            system("cls"); // Clear screen and return to main menu
                        }
                        else if (tolower(response) == 'n')
                        {
                            notacceptSuggestedSeats(seats); // Reject the seats, cancel all chosen seats, prepare for reselection
                            system("cls");               
                        }
                        else // If the user inputs an invalid character (not within options)
						{
							printf("\nInvalid input, please re-enter.\n");
							notacceptSuggestedSeats(seats); // Revert temporarily marked seats
							pressToContinue();
							system("cls");
						}
                    }
                    else // If not enough seats available, prompt user to press any key to return to the main menu
                    {
                        printf("\nNot enough seats available.\n");
                        pressToContinue();
                    }
                    break;
                    
                case 'c': 
                    // If 'c. Choose by yourself' is selected from the menu
                    // Enter the seat map to let the user choose seats freely
                    chooseSeats(seats);
                    break;

                case 'd':
                    keepRunning = exitConfirmation();
                    // Determine when to exit the loop (press 'N' to exit the loop)
                    
                    // After pressing 'd', the user can input 'y', 'Y', 'n', or 'N', handled by the exitConfirmation() function
                    // After entering the function, if successful: return value is 1, if failed return value is 0.
                    // If the returned value is 0,
                    // keepRunning will be set to 0,
                    // Then proceed to be blocked by while(keepRunning),
                    // Because while(0) means false, it will be considered not executable,
                    // And finally return 0;

                    break;