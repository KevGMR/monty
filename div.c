#include "monty.h"

/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (h->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	h->next->n /= h->n;
	*head = h->next;
	free(h);
}
