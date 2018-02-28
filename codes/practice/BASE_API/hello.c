#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMN 20
#define MAX_LINE_INPUT 100

int read_column_numbers(int column[], int max);
void rearrange(char * output, const char * input, int n_columns, int column[]);

int main (int argc, char ** argv){

  int n_columns;
  int column[MAX_COLUMN];
  char input [MAX_LINE_INPUT];
  char output [MAX_LINE_INPUT];

  n_columns = read_column_numbers(column, MAX_COLUMN);

  while (gets(input) != NULL){
    printf("Origin string is :%s \n", input);
    rearrange(output, input, n_columns, column);
    printf("After rearrange :%s \n", output);
  }

  return EXIT_SUCCESS;
}

int read_column_numbers(int column[], int max){
  int num = 0;
  char ch;

  while (num <= max &&
         scanf("%d", &column[num]) != 0 &&
         column[num] != -1)
    num++;

  if (num % 2 == 1){
    printf("Last column number is not pair\n");
    exit(EXIT_FAILURE);
  }

  while ((ch = getchar()) != EOF && ch != '\n')
    ;

  return num;
}

void rearrange(char * output , const char * input,
               int n_columns, int column[]){
  int i ;
  int output_col;
  int len;

  len = strlen( input );
  output_col = 0;

  for (i = 0; i < n_columns; i++){
    int nchar = column[i+1] - column[i] + 1;

    if (column[i] >= len ||
        output_col == MAX_LINE_INPUT - 1)
      break;

    if (nchar + output_col > MAX_COLUMN -1)
      nchar = MAX_COLUMN - output_col - 1;

    strncpy(output + output_col, input + column[i], nchar);
    output_col += i;
  }
  output[output_col] = '\0';
}
