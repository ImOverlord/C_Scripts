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
}Node;

Node *create_list()
{
	Node *head = NULL;

	return (head);
}

Node *add_element(Node *head, int data)
{
	Node *current = head;
	Node *newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL) {
		exit (84);
	}
	newNode->data = data;
	newNode->next = NULL;

	if (!head) {
		head = newNode;
	} else {
		newNode->next = current;
		head = newNode;
	}
	return (head);
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

Node *delete1(Node *head, int data)
{
	Node *current = head;
	Node *previous = NULL;
	if (!current) {
		return (NULL);
	}

	while (current) {
		if (current->data == data) {
			if (!previous) {
				head = current->next;
			} else {
				previous->next = current->next;
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
