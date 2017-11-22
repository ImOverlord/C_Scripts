/*
** EPITECH PROJECT, 2017
** chianed_link.h
** File description:
**	Sample header file for chained link
*/
#ifndef CHAINED_LINKED_H
#define CHAINED_LINKED_H

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
	struct node *previous;
}Node;

Node *create_list()
{
	Node *head = NULL;

	return (head);
}
Node *get_last(Node *element)
{
	if (!element)
		return (NULL);
	while (element->next) {
		element = element->next;
	}
	return (element);
}
Node *get_first(Node *element)
{
	if (!element)
		return (NULL);
	while (element->previous)
		element = element->previous;
	return (element);
}
Node *add_first(Node *head, int data)
{
	Node *current = get_first(head);
	Node *newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL) {
		exit (84);
	}
	newNode->data = data;
	newNode->next = NULL;
	newNode->previous = NULL;

	if (!current) {
		head = newNode;
	} else {
		current->previous = newNode;
		newNode->next = current;
		head = newNode;
	}
	return (head);
}
Node *add_end(Node *element, int data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	
	if (newNode == NULL)
		exit(84);
	if (!element)
		return (NULL);
	element = get_last(element);
	element->next = newNode;
	newNode->data = data;
	newNode->previous = element;
	newNode->next = NULL;
	return (newNode);
}
int size(Node *head)
{
	Node *current = head;
	int counter = 0;

	if (!current)
		return (0);
	while (current) {
		counter++;
		current = current->next;
	}
	return (counter);
}
Node *delete(Node *head, int data)
{
	Node *current = head;
	Node *previous = NULL;
	Node *next = NULL;
	if (!current)
		return (NULL);
	while (current) {
		if (current->data == data) {
			if (!previous) {
				head = current->next;
			} else {
				previous->next = current->next;
				next = current->next;
				next->previous = previous;
			}
			free(current);
			return (head);
		}
		previous = current;
		current = current->next;
	}
	return (head);
}
#endif
