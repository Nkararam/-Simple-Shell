#include "file.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;
if (*s == '+')
s++;  /* TODO: why does this make main return 255? */
for (i = 0;  s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result *= 10;
result += (s[i] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
write(STDERR_FILENO, info->fname, _strlen(info->fname));
write(STDERR_FILENO, ": ", 2);
print_d(info->line_count, STDERR_FILENO);
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, info->argv[0], _strlen(info->argv[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, estr, _strlen(estr));
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
char buffer[20];
int count = 0;
int i = 0;
unsigned int _abs_, current;
if (input < 0)
{
_abs_ = -input;
count += write(fd, "-", 1);
}
else
{
_abs_ = input;
}
current = _abs_;
do

{
buffer[i++] = '0' + current % 10;
current /= 10;
} while (current != 0);
while (i > 0)
{
count += write(fd, &buffer[--i], 1);
}
return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;
if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do

{
*--ptr = array[n % base];
n /= base;
} while (n != 0);
if (sign)
*--ptr = sign;
return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
int i;

for (i = 0; buf[i] != '\0'; i++)
if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
{
buf[i] = '\0';
break;
}
}
