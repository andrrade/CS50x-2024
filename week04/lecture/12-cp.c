#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb"); // rb = read binary mode;
    FILE *dst = fopen(argv[2], "wb"); // wb = write to it in binary

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0) // b = pass by value; &b = pass by reference
    {
        fwrite(&b, sizeof(b), 1, dst);
    }
    fclose(dst);
    fclose(src);
}
