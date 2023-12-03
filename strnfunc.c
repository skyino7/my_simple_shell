#include "main.h"

/* BELLOW ARE THE CUSTOM BUILTIN FUNCTIONS FOR MANIPULATING STRINGS */

/**
 * _strlen - returns the length of a string
 * @s: string to get the length of
 * Return: the length of the string
 */
size_t _strlen(const char *s)
{
	size_t i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: the concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	size_t i = 0;

	while (dest[i] != '\0')
		i++;
	_strcpy(&dest[i], src);
	return (dest);
}

/**
 * _strcpy - copies a string to another
 * @dest: destination string
 * @src: source string
 * Return: the number of characters copied
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i = 0;

	for (i = 0; i != _strlen(src); i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
