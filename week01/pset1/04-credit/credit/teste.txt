#include <cs50.h>
#include <stdio.h>

// Function prototypes
long input(void);
bool checkSum(long number);
int get_length(long number);
int get_prefix(long number);
void checkCard(long number);

int main(void)
{
    // Get the credit card number from the user
    long number = input();

    // Check if the credit card number is valid
    if (checkSum(number))
    {
        // If valid, determine and print the card type
        checkCard(number);
    }
    else
    {
        // If not valid, print INVALID
        printf("INVALID\n");
    }

    return 0;
}

// Function to read the credit card number from the user
long input(void)
{
    long number;
    // Keep asking for a number until a positive number is entered
    do
    {
        number = get_long("Number: ");
    }
    while (number <= 0);
    return number;
}

// Function to calculate the checksum and verify validity using Luhn's algorithm
bool checkSum(long number)
{
    long sum = 0;           // Variable to store the sum of digits
    bool alternate = false; // Flag to alternate between multiplying and not

    // Iterate over the digits of the number
    while (number > 0)
    {
        int digit = number % 10; // Get the last digit
        number /= 10;            // Remove the last digit from the number

        // If alternate is true, multiply the digit by 2
        if (alternate)
        {
            digit *= 2;
            // If the result is more than 9, subtract 9 (or add the individual digits)
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;           // Add the processed digit to the sum
        alternate = !alternate; // Toggle the alternate flag
    }

    // Return true if the total sum modulo 10 is 0 (valid), otherwise false (invalid)
    return (sum % 10 == 0);
}

// Function to get the length of the credit card number
int get_length(long number)
{
    int length = 0; // Variable to store the length of the number
    // Count the number of digits in the number
    while (number > 0)
    {
        number /= 10; // Remove the last digit
        length++;     // Increment the length
    }
    return length;
}

// Function to get the prefix of the credit card number
int get_prefix(long number)
{
    // Keep removing the last digit until we are left with the first few digits (prefix)
    while (number >= 100)
    {
        number /= 10;
    }
    return number; // Return the prefix
}

// Function to determine and print the type of the credit card
void checkCard(long number)
{
    int length = get_length(number); // Get the length of the number
    int prefix = get_prefix(number); // Get the prefix of the number

    // Check the length and prefix to determine the card type
    if (length == 15 && (prefix == 34 || prefix == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (prefix >= 51 && prefix <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (prefix / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
