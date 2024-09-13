#include <cs50.h>
#include <stdio.h>

int length_string(string s);

int main(void)
{
  string name = get_string("Name: ");
  length_string(name);
}

int length_string(string s)
{
  int n = 0;

  while(s[n] != '\0')
  {
    n++;
  }
  return n;
}
