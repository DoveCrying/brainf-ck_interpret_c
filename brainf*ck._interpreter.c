#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>

void printResult(int* result, int result_pointer)
{
  printf("\nOutput Brainfuck code:\n");
  for (int j = 0; j < result_pointer; j++)
  {
    // Used wchar.h to allow conversion from int to ascii character
    wint_t character = (wint_t)result[j];
    printf("%c", character);
  }
}

void interpreter(char* code)
{

  // Auxiliary variable for user input§
  int userInput;

  // Results
  int result [5000];
  int result_pointer = 0;

  // Loop
  int loops [20000];
  int loop_pointer = 0;
  // Flag used to ignore all instructions after a [ when the value is 0, until the following ]
  bool flag = false;

  // Exception

  // pointer
  int pointer = 0;
  int space[20000];

  // Initialize the array with 0's
  for (int i = 0; i < 20000; i++) 
  {
      space[i] = 0;
  }

  int i =0;
  while(code[i] != '\0')
  {
    if (flag)
    {
      if (code[i] == ']')
      {
        flag = false;
      }
        i++;
        continue;
    }
    // Switch statement (acting as a lexer)
    switch (code[i])
    {
      // Increase the current block by one
      case '+':
        if (space[pointer] == 255)
        {
          space[pointer] = 0;
        }
        else
        {
          space[pointer]++;
        }
      break;

      // Decrease the current block by one
      case '-':
        if (space[pointer] == 0)
        {
          space[pointer] = 255;
        }
        else
        {
          space[pointer]--;
        }
      break;

      // Move one block to the right
      case '>':
        pointer++;
        break;
      
      // Move one block to the left 
      case '<':
        pointer--;
        break;

      // Store jump location, if 0, skip loop
      case '[':
        if (space[pointer] == 0)
        {
            flag = true;
        }
        else
        {
          loops[loop_pointer] = i;
        }
        break;

      // if not 0, jump back to previous [, otherwise move to next instruction
      case ']':
        if (space[pointer] == 0)
        {
            loop_pointer--;
        }
        else
        {
          i = loops[loop_pointer];
        }
        break;

      // Store the value of the current block
      case '.':
        result[result_pointer] = space[pointer];
        result_pointer++;
        break;

      // Input a value into the current block
      case ',':
        printf("Insert Input: ");
        scanf("%d", &userInput);
        space[pointer] = userInput;
        break;
    }
    i++;
  }
  printResult(result,result_pointer);
}


int main()
{
  printf("=========Brainf*ck Interpreter=========\n");
  char brainCode[20000];
  printf("Input your Brainfuck code:\n");
  scanf("%s",brainCode);
  interpreter(brainCode);
  return 1;
}
