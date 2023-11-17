#include "shell.h"
/**
 * *_strcpy - copies the string pointed to by src
 * to the buffer pointed to by dest.
 * @dest: pointer to the buffer
 * @src: pointer to the string we copy
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * *_strcat - concatenates two strings
 * @dest: pointer to destination string
 * @src: pointer to source string
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{

	}
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';
	return (dest);
}
/**
 * _strspn - gets the length of a prefix substring.
 * @s: pointer to string to get lenght of substring from
 * @accept: pointer to string which contains bytes we
 * search from in s
 * Return: number of bytes in the initial segment of s
 * which consist only of bytes from accept
 */
int _strspn(char *s, char *accept)
{
	int i, j;
	int count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		int found = 0;

		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				count++;
				break;
			}
		}
		if (found == 0)
			return (count);
	}
	return (1024);
}
/**
 * _atoi - converts a string to an integer.
 * @s: pointer to the string
 * Return: the integer, otherwise 0 if no int in the string
 */
int _atoi(char *s)
{
	int i;
	unsigned int result = 0;
	unsigned int last_digit;
	int sign = 1;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			last_digit = s[i] - '0';
			result = result * 10 + last_digit;
			if (s[i + 1] > '9' || s[i + 1] < '0')
			{
				break;
			}
		}
		else if (s[i] > '9' || s[i] < '0')
		{
			continue;
		}
	}
	return (result * sign);
}
