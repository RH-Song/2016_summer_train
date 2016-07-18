

#include <stdio.h>
#include <system.h>
#include <altera_avalon_performance_counter.h>

#define USE_ONCHIP_MEMORY

 #ifdef USE_ONCHIP_MEMORY
  int first[10][10] __attribute__ (( section ( ".onchip_memory2_0" )));
  int second[10][10] __attribute__ (( section ( ".onchip_memory2_0" )));
  int multiply[10][10] __attribute__ (( section ( ".onchip_memory2_0" )));
 #else
  int first[10][10];
  int second[10][10];
  int multiply[10][10];
 #endif

int main()
{
  int m, n, p, q, c, d, k, sum = 0;



  printf("Enter the number of rows and columns of first matrix\n");
  scanf("%d%d", &m, &n);
  printf("Enter the elements of first matrix\n");

  for (  c = 0 ; c < m ; c++ )
    for ( d = 0 ; d < n ; d++ )
      scanf("%d", &first[c][d]);

  printf("Enter the number of rows and columns of second matrix\n");
  scanf("%d%d", &p, &q);

  if ( n != p )
    printf("Matrices with entered orders can't be multiplied with each other.\n");
  else
  {
    printf("Enter the elements of second matrix\n");

    for ( c = 0 ; c < p ; c++ )
      for ( d = 0 ; d < q ; d++ )
        scanf("%d", &second[c][d]);

 /* Here starts the real multiplication. You should profile the following block of code*/

    PERF_START_MEASURING( (void*) PERFORMANCE_COUNTER_BASE);
    for ( c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < q ; d++ )
      {
        for ( k = 0 ; k < p ; k++ )
        {
          sum = sum + first[c][k]*second[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      }

    alt_u64 x = perf_get_total_time((void*) PERFORMANCE_COUNTER_BASE);
    printf("Finished in %u clock cycles\n", x);
 /*Calculations are done now. Stop profiling now*/

    printf("Product of entered matrices:-\n");

    for ( c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < q ; d++ )
        printf("%d\t", multiply[c][d]);

      printf("\n");
    }
  }



  return 0;
}



#include <stdio.h>
#include <system.h>
#include <unistd.h>

int main()
{

	unsigned int ch = 0;
	unsigned int *pLed = (unsigned char*)(LED_BASE);
	while(1)
	{
		*pLed = ch;
		ch = ~ch;
		usleep(1000000);
	}


  return 0;
}

