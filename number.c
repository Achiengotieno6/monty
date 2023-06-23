#include "monty.h"
#include <stddef.h>
/**
 * check_number - checks if str is number
 * @str_: string to check
 * Return: 1 or 0
 */
int check_number(char *str_)
{
	int w;

	if (!str_)
		return (0);
	for (w = 0; str_[w]; w++)
	{
		if (w < '0' || w > '9')
			return (0);
	}
	return (1);
}
