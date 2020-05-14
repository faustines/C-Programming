#include <math.h>
#include <stdlib.h>
#include <stdio.h>

double random_coordinate ();

int
main ()
{
  double seed;
  int i, samples = 10000000, hits = 0;

  printf ("Enter a seed value: ");
  scanf ("%lf", &seed);
  // printf("Enter number of samples: ");
  // scanf("%d", &samples);

  srand (seed);
  for (i = 0; i < samples; ++i)
    {
      if (sqrt (pow (1 - random_coordinate (), 2) +
		pow (1 - random_coordinate (), 2)) < 1)
	{
	  hits = hits + 1;
	}
    }

  printf ("Pi is approximately %.2f\n",
	  4.0 * ((double) hits / (double) samples));

  return 0;
}

double
random_coordinate ()
{
  return (rand () % 100000) / 50000.0;
}
