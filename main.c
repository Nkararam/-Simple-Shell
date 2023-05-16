#include <stdio.h>
#include "add.h"
int add(int num1, int num2);

int main(void)
{
int num1 = 5;
int num2 = 10;
int sum = add(num1, num2);
printf("The sum is: %d\n", sum);

return (0);
}
