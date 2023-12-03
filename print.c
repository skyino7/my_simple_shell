#include "main.h"

/**
 * _putchar - write a  character
 * @c: the character to write
 * Return: the number of character written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print - prints a string
 * @str: the string to print
 * Return: the number of characters printed
 */
int _print(char *str)
{
	int count = 0;

	/* loop through the characters in the string and print them */
	while (*str != '\0')
	{
		_putchar(*str++);
		count++;
	}

	return (count);
}

/**
 * _printnotfound - prints the command not found message
 * @args: the arguments passed to the shell
 * @argv: argument from main function
 * @count: count
 * Return: 0
 */
int _printnotfound(int *count, char **args, char **argv)
{
	int argslen = strlen(args[0]), argvlen = strlen(argv[0]);
	char error[11] = ": not found";
	char num = *(count) + '0';
	char *message = malloc(strlen(error) + num + argslen + argvlen + 5);

	if (message == NULL)
		return (-1);

	_strcpy(message, argv[0]);
	_strcat(message, ": ");
	_strcat(message, &num);
	_strcat(message, ": ");
	_strcat(message, args[0]);
	_strcat(message, error);
	_strcat(message, "\n");

	write(2, message, _strlen(message));

	free(message);

	return (0);
}
