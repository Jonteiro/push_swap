/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:56:12 by marvin            #+#    #+#             */
/*   Updated: 2023/08/31 11:56:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

typedef struct	s_list
{
	void			*content;
	size_t 			content_size;
	struct s_list 	*next;
}					t_list;

/*
ARROW OPERATOR ->
STRUCT STUDENT
INT AGE
CHAR *PASSWORD

STUDENT -> AGE = 22;
STUDENT -> PASSWORD = STUPIDSIMPLE;
*/

t_list *ft_lstnew(void const *content, size_t content_size)
{
    t_list *new_node = (t_list *)malloc(sizeof(t_list));

    if (new_node == NULL) {
        return NULL; // Allocation failed, return NULL
    }

    if (content == NULL) {
        new_node->content = NULL;
        new_node->content_size = 0;
    } else {
        new_node->content = malloc(content_size);
        if (new_node->content == NULL) {
            free(new_node); // Allocation for content failed, free the node and return NULL
            return NULL;
        }
        memcpy(new_node->content, content, content_size);
        new_node->content_size = content_size;
    }

    new_node->next = NULL; // Initialize the next pointer to NULL
    return new_node;
}
/*Allocates (with malloc(3)) and returns a “fresh” link. The
variables content and content_size of the new link are initialized by copy of the parameters of the function. If the parameter content is nul, the variable content is initialized to
NULL and the variable content_size is initialized to 0 even
if the parameter content_size isn’t. The variable next is
initialized to NULL. If the allocation fails, the function returns
NULL.*/


void ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
    if (alst == NULL || *alst == NULL) {
        return; // If alst is NULL or points to NULL, there's nothing to delete
    }

    // Call the del function to free the content of the node
    if ((*alst)->content != NULL) {
        del((*alst)->content, (*alst)->content_size);
    }

    // Free the memory of the node itself
    free(*alst);

    // Set the pointer to NULL to indicate that the node has been deleted
    *alst = NULL;
}
/*Takes as a parameter a link’s pointer address and frees the
memory of the link’s content using the function del given as
a parameter, then frees the link’s memory using free(3). The
memory of next must not be freed under any circumstance.
Finally, the pointer to the link that was just freed must be
set to NULL (quite similar to the function ft_memdel in the
mandatory part).
*/

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
    if (alst == NULL || *alst == NULL) {
        return; // If alst is NULL or points to NULL, there's nothing to delete
    }

    t_list *current = *alst;
    t_list *next;

    while (current != NULL) {
        next = current->next; // Store the next node's address
        if (current->content != NULL) {
            del(current->content, current->content_size); // Free content
        }
        free(current); // Free the node itself
        current = next; // Move to the next node
    }

    // Set the pointer to the first link to NULL to indicate that the list is empty
    *alst = NULL;
}
/*
Takes as a parameter the adress of a pointer to a link and
frees the memory of this link and every successors of that link
using the functions del and free(3). Finally the pointer to
the link that was just freed must be set to NULL (quite similar
to the function ft_memdel from the mandatory part).
*/

void ft_lstadd(t_list **alst, t_list *new) {
    if (alst == NULL || new == NULL) {
        return; // If alst or new is NULL, there's nothing to add
    }

    new->next = *alst; // Set the next pointer of the new node to the current first node
    *alst = new; // Update the pointer to the first node to point to the new node
}
// Adds the element new at the beginning of the list.

void ft_lstiter(t_list *lst, void (*f)(t_list *elem)) {
    if (lst == NULL || f == NULL) {
        return; // If lst is NULL or f is NULL, there's nothing to iterate or apply
    }

    t_list *current = lst; // Start with the first link

    while (current != NULL) {
        f(current); // Apply the function f to the current link
        current = current->next; // Move to the next link
    }
}
// Iterates the list lst and applies the function f to each link.



//  Iterates a list lst and applies the function f to each link to
// create a “fresh” list (using malloc(3)) resulting from the successive applications of f. If the allocation fails, the function
// returns NULL.

t_list *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem)) {
    if (lst == NULL || f == NULL) {
        return NULL; // If lst is NULL or f is NULL, there's nothing to map
    }

    t_list *new_list = NULL; // Initialize the new list as empty
    t_list *current = lst; // Start with the first link

    while (current != NULL) {
        t_list *new_node = f(current); // Apply the function f to the current link

        if(new_node == NULL) {
            ft_lstclear(&new_list, free); // Free the new list if the function f fails
            return NULL; // Allocation failed, return NULL
        }

        // Add the new_node to the end of the new list
        if (new_list == NULL) {
            new_list = new_node;
        } else {
            t_list *last_node = new_list;
            while (last_node->next != NULL) {
                last_node = last_node->next;
            }
            last_node->next = new_node;
        }

        current = current->next; // Move to the next link
    }

    return new_list; // Return the new list
}


/*
// Struct to hold the num  and the pointer to the next element.
struct	element{ 
	int num;
	struct element* next; 
};
// Append the new element to the start of the stack
void push(int num, struct element** stack){
	struct element* Element = (struct element*)malloc(sizeof(struct element));
	Element -> num = num; 
	Element -> next = *stack;  
	(*stack) = Element;  
}
// Remove element from the top of the stack
void pop(struct element** stack){
	if(*stack != NULL){
		printf("Element popped: %c\n",(*stack) -> num);
		struct element* tempPtr = *stack;
		*stack = (*stack) -> next;
		free(tempPtr);
	}
	else{
		printf("The stack is empty.\n");
	}
}
// Display the element at the top of the stack
void    top(struct element* stack){
	if       (stack != NULL){
	printf("Element on top: %c\n", stack -> num);
	}
	else{
		printf("The stack is empty.\n");
	}
}
*/

/*
int main() {
	struct element* root = (struct element*)malloc(sizeof(struct element));
	root -> num = 'a';
	root -> next = NULL;
	top(root);
	push('b',&root);
	top(root);
	push('c',&root);
	return 0;
}
*/