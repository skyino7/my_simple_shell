#include "main.h"

/* BELLOW ARE THE CUSTOM BUILTIN FUNCTIONS FOR MANIPULATING STRINGS */

/**
 * _strdup - returns a duplicate of a string
 * it dynamically allocates a memory for the duplicate.
 * @str: string to be duplicated
 * Return: the duplicated string
 */
char *_strdup(const char *str)
{
	char *dup;
	size_t len = 0;

	if (str == NULL)
		return (NULL);

	/* Calculate the size of the string */
	len = _strlen(str);

	/* Allocate memory for the duplicate, including the null terminator */
	dup = malloc(sizeof(char) * (len + 1));

	/* Check if memory was allocated */
	if (dup == NULL)
		return (NULL);

	/* Copy the string */
	_strcpy(dup, str);
	return (dup);
}

/**
 * _strncmp - compares two strings
 * @s1: first string
 * @s2: second string
 * @n: number of characters to compare
 * Return: any if the strings are not equal or 0 if they are equal
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		/* compare the characters */
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: any if the strings are not equal or 0 if they are equal
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
