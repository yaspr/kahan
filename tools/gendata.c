#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

//
int main(int argc, char **argv)
{
  //Check arguments count
  if (argc < 3)
    return printf("OUPS: %s [file name] [nb elements]\n", argv[0]), -1;

  //Use time as a seed
  srand(time(NULL));
  
  uint64_t n = atoll(argv[2]);
  FILE   *fd = fopen(argv[1], "wb"); 

  //Generate random values < 1
  for (uint64_t i = 0; i < n; i++)
    fprintf(fd, "%f ", ((float)rand() / RAND_MAX));

  fprintf(fd, "\n");
  
  fclose(fd);

  return 0;
}
