#include <stdio.h>  
#include <string.h>
#include <stdbool.h>

void converter(char* code)
{
  // Brainf*ck commands
  char plus = '+';
  char minus = '-';
  char next = '>';
  char previous = '<';
  char bloop = '[';
  char eloop = ']';
  char save = '.';
  char input = ',';

  char result [1000];
  int currChar = 0;
  int prevChar = 0;
  int difference;
  int remnant;
  int i =0;
  while(code[i] != '\0')
  {
    currChar = code[i];
    difference = currChar - prevChar;
    if (difference < 0)
    {
        for (int j = 0; j > difference; j--)
        {
          strncat(result,&minus,1);
        }
      
    }
    else
    {
      for (int j = 0; j < difference; j++)
      {
        strncat(result,&plus,1);
      }
    }
    prevChar = currChar;
    strncat(result,&save,1);
    i++;
  }
  printf("Result: \n");
  printf("%s", result);
}
int main()
{
  char stringBrain[500];
  printf("Enter String to convert into Brainf*ck Code: \n");
  scanf("%s", stringBrain);
  converter(stringBrain);
}
