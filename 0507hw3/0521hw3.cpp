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
void notAcceptSuggestedSeats(int seats[ROWS][COLS]);   // Reject suggested seats, cancel all chosen seats, prepare for reselection
int suggestSeats(int seats[ROWS][COLS], int numSeats); // Auto seat selection functionality
void acceptSuggestedSeats(int seats[ROWS][COLS]);      // Accept seats (after manual or auto selection, ask if user accepts)
int findFourSeats(int seats[ROWS][COLS]);
// Open the seat selection function after user clicks auto-select
// (because the logic for selecting four seats is different from general seat selection logic, mainly in the arrangement)

int main()
{
    int seats[ROWS][COLS]; // Set up a 9x9 seat map
    char choice;           // Set 'choice' as the character input by the user after viewing the menu
    int keepRunning = 1;   // See the comments in the switch function for case 'd'

    if (checkPassword()) // After entering the if-else function, immediately check if the password is correct. If correct, enter the main code
    {
        initializeSeats(seats); // Initialize the seat map
        do
        {
            menu();                // Display a personalized welcome screen
            fflush(stdin);         // Clear the buffer, system("cls"); clears the screen
            scanf(" %c", &choice); // Read the user's menu selection
            choice = tolower(choice);
            // 0516 Need to look up the definition of tolower() function
            // tolower() function converts uppercase letters to lowercase directly, so no need to write four more lines for 'case 'A'' in case

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
                        notAcceptSuggestedSeats(seats); // Reject the seats, cancel all chosen seats, prepare for reselection
                        system("cls");
                    }
                    else // If the user inputs an invalid character (not within options)
                    {
                        printf("\nInvalid input, please re-enter.\n");
                        notAcceptSuggestedSeats(seats); // Revert temporarily marked seats
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

            default:
                printf("\nInvalid input, please re-enter.\n");
                pressToContinue();
                break;
            }
        } while (keepRunning);
    }
    else
    {
        printf("\nPassword input error three times, the program will end soon.");
    }

    return 0;
}

int checkPassword()
{
    int password, frequency = 0, correctPassword = 2024;
    // First question
    printf("This is the welcome screen, this is an owl\n");
    printf("                           .__.\n");
    printf("                          (o,o)\n");
    printf("                         -|=|-\n");
    printf("                        __|__\n");
    printf("                     // ' ' \\\\\n");
    printf("                  _ //   ^   \\\\\n");
    printf("                 / \\(  '  '  )//\n");
    printf("                /  / \\(-----)/ \\  \\\n");
    printf("                | |   (:| |:)   | |\n");
    printf("                | |    || ||    | |\n");
    printf("                | |    () ()    | |\n");
    printf("                | |    || ||    | |\n");
    printf("               /  \\   || ||   /  \\\n");
    printf("              /    \\  || ||  /    \\\n");
    printf("             /  /\\  \\=====/ /\\  \\ \\\n");
    printf("            /__/  \\__|___|__/  \\__\\\n");
    printf("           |_______________________|\n");
    
    while (frequency < 3)
    {
        //When the password is entered more than three times,
        //it will stop accepting user input and stop the program.
        printf("Please enter password:");
        fflush(stdin);
        scanf("%d", &password);
        if (password == correctPassword)
        {
            return 1;
        }
        else
        {
            printf("\nPassword incorrect! You have %d frequency left.\n", 2 - frequency);
            frequency++;
        }
    }
    return 0;
}

void menu() // Display menu
{
    system("cls");
    printf("|----------[BookingSystem]-----------|\n");
    printf("|  a. Available seats                |\n");
    printf("|  b. Arrange for you                |\n");
    printf("|  c. Choose by yourself             |\n");
    printf("|  d. Exit                           |\n");
    printf("|------------------------------------|\n");
    printf("Please choose one of the options:");
}

void pressToContinue() 
// "Press any key to continue" for convenience, to simplify the program and improve efficiency
{
    printf("\nPress any key to continue...");
    getch(); 
    //The program continues execution only after 
    //receiving input from any key on the keyboard.
    //Give users more time to read the displayed message.
}

void initializeSeats(int seats[ROWS][COLS])
{
    srand(time(NULL)); 
    // time(NULL) has a fixed form and cannot be modified
    // It constantly updates until this function is used
    // It stops the function and gets a random variable
    // Because the execution time of the program can never be the same to 0.000... seconds
    // After closing the program, this function will automatically update the time, so the problem of the same random variable does not exist
    // Initialize random seed

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // Indicates starting from the first row.
            // i < ROWS;: Condition check to ensure the value of i is within valid range (less than the total number of rows).
            // i++: Increment i after each loop to move to the next row.

            seats[i][j] = 0; 
            // Initialize all seats as empty
        }
    }

    int Reserve = 0; // Initialize the number of booked seats
    while (Reserve < 10) // Use a loop to randomly book seats until a total of 10 seats are booked.
    { // Pre-book some seats randomly
        int a = rand() % ROWS; 
        int b = rand() % COLS;
        //a and b are two variables representing rows and columns

        // rand() % ROWS:
        // Generates a random integer between 0 and ROWS-1,
        // Indicating the randomly selected row index.

        // rand() % COLS:
        // Generates a random integer between 0 and COLS-1,
        // Indicating the randomly selected column index.

        if (seats[a][b] == 0)
        {
            seats[a][b] = 1;
            // Check if the randomly selected seat is empty and mark it as booked.
            Reserve++;
        }
    }
}

void showSeats(int seats[ROWS][COLS])
{
    printf("\nSeat map:\n");
    printf("\n");
    printf("  123456789\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", seats[i][j] == 1 ? '*' : (seats[i][j] == 2 ? '@' : '-')); // Display seat status
        }
        // If the user confirms the seat, change the symbol from '@' (temporary) to '*'
        // 0, 1, 2 represent available, booked, and temporarily selected seats respectively
        printf("\n");
    }
}

int suggestSeats(int seats[ROWS][COLS], int numSeats)
{
    int lookfor = 0; 
    // Variable to indicate whether enough seats were found to meet the user's request.
    // Initialized to 0, indicating not found yet.
    if (numSeats >= 1 && numSeats <= 3)
    {
        // Try to find numSeats in a single row
        for (int i = 0; i < ROWS && !lookfor; i++)
        {
            for (int j = 0; j <= COLS - numSeats; j++)
            {
                int valid = 1; 
                // Initial setting to 1, assuming seats are valid at the start.

                for (int k = 0; k < numSeats; k++) 
                // Loop to check for valid seats sequentially
                {
                    if (seats[i][j + k] != 0)
                    {
                        valid = 0; 
                        break; 
                        // If a seat is found, set valid to 0 and break the loop
                    }
                }
                if (valid)
                // If the above code completes without changing the valid variable,
                // it indicates valid seats were found
                {
                    for (int k = 0; k < numSeats; k++)
                    {
                        seats[i][j + k] = 2;
                        // Set the seats as temporarily selected
                    }
                    lookfor = 1;
                    break;
                }
            }
        }
    }
    // If numSeats is within 1 to 3,
    // The function tries to find these seats in the same row.
    // If numSeats is 4,
    // The function calls findFourSeats to try to find four contiguous seats or two adjacent rows with two seats each.

    else if (numSeats == 4)
    {
        // Try to find 4 seats in one row or two consecutive rows with 2 seats each
        lookfor = findFourSeats(seats);
        // If the user wants to select four seats,
        // The requirement is that the four people either sit in the same row or form a square.
        // The seat allocation method is different from the case of 1, 2, or 3 seats.
    }

    return lookfor; 
    // Return the value of 'lookfor' indicating whether enough seats were found for the user's request.
}

int findFourSeats(int seats[ROWS][COLS])
{
    int lookfor = 0; 
    // Initialize found to 0

    // First, try to find 4 continuous seats in one row
    for (int i = 0; i < ROWS && !lookfor; i++)
    {
        for (int j = 0; j <= COLS - 4; j++)
        {
            if (seats[i][j] == 0 && seats[i][j + 1] == 0 && seats[i][j + 2] == 0 && seats[i][j + 3] == 0)
            {
                //Check if there are four consecutive empty seats
                for (int k = 0; k < 4; k++)
                {
                    seats[i][j + k] = 2;
                }
                lookfor = 1;
                break;
            }
        }
    }

    // If not found, try two consecutive rows with 2 seats each
    if (!lookfor)
    {
        for (int i = 0; i < ROWS - 1 && !lookfor; i++)
        {
            for (int j = 0; j <= COLS - 2; j++)
            {
                if (seats[i][j] == 0 && seats[i][j + 1] == 0 &&
                    seats[i + 1][j] == 0 && seats[i + 1][j + 1] == 0)
                //Check whether the 2x2 area with (i, j) as the upper left corner
                // in the seating chart is all empty seats
                
                {
                    seats[i][j] = 2;
                    seats[i][j + 1] = 2;
                    seats[i + 1][j] = 2;
                    seats[i + 1][j + 1] = 2;
                    //If the if condition is true, it means a 2x2 area is found,
                    //Here, set the seat status of this area to 2,
                    //Indicates that these seats are temporarily selected.
                    lookfor = 1;
                    break;
                }
            }
        }
    }

    return lookfor;
}

void acceptSuggestedSeats(int seats[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (seats[i][j] == 2)
            {
                seats[i][j] = 1; // Confirm the seat selection by marking it reserved
            }
        }
    }
}

void notacceptSuggestedSeats(int seats[ROWS][COLS])
{
    // Define a function named notacceptSuggestedSeats that accepts a 2D seat array as a parameter,
    // and reverts all temporarily selected seats back to empty state.
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (seats[i][j] == 2) // Check if the current seat is temporarily selected
            {
                seats[i][j] = 0; // Revert the current temporarily selected seat state from 2 to empty state 0
                // Revert suggested seats back to empty
            }
        }
    }
}

void chooseSeats(int seats[ROWS][COLS])
{
    int row, col; // Variables to store row and column
    char input[10]; // Array to store user input for row and column number
    char response; // Variable to store the user's response while making choices
    int totalSeats = 0; // Count the number of seats chosen by the user

    while (1) // Loop for seat selection until 'q' or 'Q' is entered
    {
        printf("\nPlease enter seat choice (format like 1-2 for Row 1, Column 2) or enter 'Q' or 'q' to finish choosing: ");
        fflush(stdin);
        scanf("%s", input);

        if (tolower(input[0]) == 'q')
        { 
            // If the user inputs 'q' or 'Q' (quit), end the seat selection
            break;
        }

        if (sscanf(input, "%d-%d", &row, &col) == 2 && row >= 1 && row <= ROWS && col >= 1 && col <= COLS)
        {   
            // Allow the user to select seats in the format of integer-integer, e.g., 2-1 for Row 2, Column 1

            // sscanf: Extracts data from an existing string.
            // Useful for handling configuration file contents, network protocol data, or other formatted strings.

            // scanf: Suitable for reading data from user input,
            // For example, obtaining user input from the console.

            // sscanf(input, "%d-%d", &row, &col):
            // This code uses the sscanf function to parse the user's input string (input),
            // And attempts to convert it into two integers (row and col).
            // The format parsed is "%d-%d", indicating parsing input like 1-2,
            // Where 1 and 2 will be parsed as integers and stored in row and col.

            // The return value of sscanf is the number of successfully parsed items,
            // If two integers are successfully parsed, the return value should be 2.
            
            // row >= 1 && row <= ROWS && col >= 1 && col <= COLS:
            // Check if the parsed row and col are within valid range,
            // The row number (row) should be between 1 and ROWS,
            // The column number (col) should be between 1 and COLS.

            if (seats[row - 1][col - 1] == 0)
            {
                // Check if the user-selected seat is empty
                // 0 and 2 in seats[][] function represent empty and temporarily selected seats respectively
                
                // Since seat row and column start from 1, but array index starts from 0,
                // Adjust to [row - 1]
                
                seats[row - 1][col - 1] = 2;
                // 2 represents temporarily selected

                totalSeats++; // Increment seat count
            }
            else
            {
                printf("Error: The seat is already booked or unavailable.\n");
                // Display warning message if seat is not empty
            }
        }
        else
        {
            printf("Error: Incorrect input format.\n");
            // Display error message for incorrect format
        }
    }

    if (totalSeats > 0)
    {
        // After the user selects seats,
        // Display the selected seats and ask if the user is satisfied with the choices,
        // Then confirm or cancel these choices based on the user's response.
        showSeats(seats);
        printf("\nAre you satisfied with the seat choices (y/n)?: ");
        fflush(stdin);
        scanf(" %c", &response);
        if (tolower(response) == 'y')
        {
            for (int i = 0; i < ROWS; i++)
            { // Confirm choices, convert '@' to '*'
                for (int j = 0; j < COLS; j++)
                {
                    if (seats[i][j] == 2)
                    {
                        // 2: temporarily selected
                        // 1: booked
                        seats[i][j] = 1; // Confirm choice
                        // Set seats[i][j] to indicate the seat is finally confirmed and booked
                    }
                }
            }
            printf("Selection confirmed.\n");
        }
        else
        {
            notacceptSuggestedSeats(seats); 
            // Cancel all temporarily selected seats (state 2)
            // Revert unconfirmed choices
            printf("Selection reverted.\n");
            // Display cancellation message
        }
        pressToContinue();
        // Ensure the user has enough time to read the message,
        // And press a key to continue when ready.
    }

    system("cls"); // Clear the screen
}
