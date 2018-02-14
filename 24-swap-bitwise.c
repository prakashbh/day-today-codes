#include <stdio.h>
int main()
{
  int x = 20;
  int y = 10;

  x = x ^ y;
  y = x ^ y;
  x = x ^ y;
  printf("Swapped Items: x = %d, y = %d", x, y);

  return 0;
}
