#include "palindrome.h"

/**
 * rev_num - reverses an int
 * @num: the int
 * @rev: the reverse of num
 * Return: the reversed int
 **/
unsigned long rev_num(unsigned long num, unsigned long rev)
{
	if (num == 0)
		return (rev);
	rev = (rev * 10) + (num % 10);
	return (rev_num(num / 10, rev));
}

/**
 * is_palindrome - Checks if int is palindrome
 * @n: the int
 * Return: 1 if int is palindrom, and 0 if not
 **/
int is_palindrome(unsigned long n)
{
	unsigned long int_rev;

	int_rev = rev_num(n, 0);
	if (n == int_rev)
		return (1);
	return (0);
}
