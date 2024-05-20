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
