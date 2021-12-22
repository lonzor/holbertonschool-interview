#include "lists.h"

/**
 * is_palindrome - Checks if a singlyu linked list is palindrome
 * @head: double pointer in the linked list
 *
 * Return: 1 if the list is a palindrome or 0 if not
 **/
int is_palindrome(listint_t **head)
{
	if (head == NULL && *head == NULL)
		return (1);
	else
		return (is_palindrome_recursive(head, *head));
}

/**
 * is_palindrome_recursive - checks if a linked list is a palindrom
 * @head: pointer to the head node of list
 * @end: pointer to the last node of list
 * Return: 1 if it is a palindrome or 0 if not
 **/
int is_palindrome_recursive(listint_t **head, listint_t *end)
{
	if (end == NULL)
		return (1);

	if (is_palindrome_recursive(head, end->next) &&
	    (*head)->n == end->n)
	{
		*head = (*head)->next;
		return (1);
	}
	else
		return (0);
}
