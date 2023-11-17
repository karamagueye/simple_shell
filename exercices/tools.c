#include "shell.h"
/**
 * len - calculates length of a string
 * @s: string
 * Return: length
 */
int len(char *s)
{
	int l;

	for (l = 0; s[l] != '\0'; l++)
	{
	}
	return (l);
}
/**
 * _strcmp - compares two strings
 * @s1: pointer to 1st string
 * @s2: pointer to 2nd string
 * Return: integer < 0 is s1 < s2
 * > 0 if s1 > s2 and 0 if s1 = s2
 */
int _strcmp(char *s1, char *s2)
{
	int i, j, k;

	for (i = 0; s1[i] != '\0'; i++)
	{

	}
	for (j = 0; s2[j] != '\0'; j++)
	{

	}
	for (k = 0; s1[k] != '\0' && s2[k] != '\0'; k++)
	{
		if (s1[k] != s2[k])
			return (s1[k] - s2[k]);
	}
	return (i - j);
}
/**
 * *_strdup - copies a string
 * @str: pointer to the string
 * Return: pointer to a newly allocated space in memory
 * NULL if str = NULL or operation fails
 */
char *_strdup(char *str)
{
	char *p;
	int i;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
	}
	p = malloc((sizeof(char) * i) + 1);
	if (p == NULL)
		return (NULL);
	p = _strncpy(p, str, (i + 1));
	return (p);
}
/**
 * *_strncpy - copies a string
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @n: number of bytess from src it uses
 * Return: pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int j;

	for (j = 0; j < n && src[j] != '\0'; j++)
	{
		dest[j] = src[j];
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}
	return (dest);
}

