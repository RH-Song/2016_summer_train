#include <stdio.h>
#include <math.h>


//#define MULTIPLICATION_RULE_TEST
//#define LIBRARY_FUNCTION_TEST
//#define SCOPE_OF_VARIABLE_TEST
//#define UNINITIALIZED_VARIABLE_TEST
//#define VARIABLE_SIZE_TEST
//#define SWITCH_CASE_TEST
//#define NOT_RETURNING_PATH_TEST


#ifdef UNINITIALIZED_VARIABLE_TEST
	void f (bool b, int *p)
	{
	if (b)
	       *p = 3;
	}

#endif

#ifdef NOT_RETURNING_PATH_TEST
	char f(unsigned int x)
	{
		if (x < 5)
			reurn('L');
	}
#endif

int main(void)
{
#ifdef MULTIPLICATION_RULE_TEST
	unsigned char c1 = 100; 
	unsigned char c2 = 10;
	unsigned char c3 = 5;
	unsigned char c4 = (c1 * c2); 	
	unsigned char c5 = c2/c3; 
	
	c4 = c4/c3;
	c5 = c5*c1;
	
	/*Explain following outputs*/	
	printf("c4 = %c\n", c4);  
	printf("c5 = %c\n", c5);

#endif

#ifdef LIBRARY_FUNCTION_TEST
  int x = -4;
  unsigned int y; /*Change it from "unsigned int" to "int" and see the result*/
  
  y = sqrt(x);
  printf("y = %u\n", y); 
#endif

#ifdef SCOPE_OF_VARIABLE_TEST
	int x = 0;
	x++;
	{
		int x = x - 1;
	}
	printf("x = %d\n", x);
#endif

#ifdef UNINITIALIZED_VARIABLE_TEST
	int u;
 	f(false, &u);
	printf ("u= %d\n", u);
#endif

#ifdef VARIABLE_SIZE_TEST
	unsigned short a = 65535;
	unsigned char b = a;
	unsigned int c = a;
	
	printf("b = %u\n", b);
	printf("c = %u\n", c);
#endif

#ifdef SWITCH_CASE_TEST

/* write a code to demonstrate the following behavior and observe the output.
*   Switch(x)
*   {
*   	case 1:
*   		If (flag)
*   		{
*   	case 2:
*   			x = 1;
*   		}
*   		break;
*   	default:
*   		break;
*   }
*   
*/
#endif

#ifdef NOT_RETURNING_PATH_TEST
	unsigned int x = 5;
	printf("Return value = %c\n", f(x));
#endif
}

