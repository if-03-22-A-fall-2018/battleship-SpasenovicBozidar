/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			battleship.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>

#include "battleship.h"

FILE* my;
FILE* op;
static CellContent myField[FIELDSIZE][FIELDSIZE];//BUFFER
static CellContent opField[FIELDSIZE][FIELDSIZE];//BUFFER
static CellContent guess[FIELDSIZE][FIELDSIZE];//BUFFER

void load_game(){
  my = fopen("battleship.my", "r");
  op = fopen("battleship.op", "r");

  for (int i = 0; i < FIELDSIZE; ++i) {
    for (int j = 0; j < FIELDSIZE; ++j) {
      fread(&myField[i][j], sizeof(CellContent), 1, my);
      fread(&opField[i][j], sizeof(CellContent), 1, op);
      guess[i][j] = Unknown;
    }
  }
  fclose(my);
  fclose(op);
}

CellContent get_shot(int row, int col){
  if (row> -1 && row< 10 && col>-1&&col<10)
  {
    return myField[row][col];
  }
  return OutOfRange;
}


bool shoot(int row, int col){
  if(!(row> -1 && row< FIELDSIZE && col>-1&&col<FIELDSIZE ))
    {
      return false;
}
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            if(row+i> -1 && row+i< FIELDSIZE && col+j>-1&&col+j<FIELDSIZE)
            {
              guess[row+i][col+j] = opField[row+i][col+j];
            }

        }
    }
     return true;
}


CellContent get_my_guess(int row, int col){
  if (row> -1 && row< 10 && col>-1&&col<10)
  {
    return guess[row][col];
  }
return OutOfRange;
}
