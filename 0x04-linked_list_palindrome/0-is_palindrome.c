#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * _is_palindrome - Checks if a singlyu linked list is palindrome
 * @left: a pointer in the linked list
 * @right: a pointer in the linkned list
 *
 * Return: 1 if the list is a palindrome or 0 if not
 **/
int is_palindrome(listint_t **left, listint_t *right)
{
	int r;

	if (!right)
		return (1);
	r = is_palindrome(left, right->next) && ((*left)->n == right->n);

	*left = (*left)->next;
	return (r);
}
