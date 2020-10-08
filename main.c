#include <stdio.h>
#include <stdlib.h>

#include "src/matrix/matrix.h"

#include "src/image/binarization.h"

int main()
{
  char* file_name = "lib/testbmp/10x10.bmp";

  struct MatrixUCHAR mat = binarization(file_name);
  show_matrix_to_img(mat);

  SDL_Quit();
}
