#include <cs50.h>
#include <stdio.h>

int main(int argc, string array[])
{
  if (argc != 2)
  {
    printf("Missing comand-line argument\n");
    return 1;
  }
  printf("Hello, %s\n", argv[1]);
  return 0;
}
