#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Define the size of a memory block (512 bytes)
#define BLOCK_SIZE 512

// Define a type for a byte (unsigned 8-bit integer)
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments is provided
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // Open the input file (card.raw)
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    FILE *output_file = NULL; // Pointer to the current JPEG file
    int file_count = 0;       // To keep track of the number of JPEGs found
    char filename[8];         // To store filenames like "###.jpg"

    // Read the input file in blocks of 512 bytes
    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, input_file) == BLOCK_SIZE)
    {
        // Check if the block is the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // If we are already writing to a file, close the current file
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Create a new JPEG file
            sprintf(filename, "%03i.jpg", file_count);
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                printf("Could not create file.\n");
                return 1;
            }

            // Increment the file count
            file_count++;
        }

        // If we are already writing a JPEG file, write the current block to it
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, output_file);
        }
    }

    // Close any remaining files
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    // Close the input file
    fclose(input_file);

    return 0;
}
