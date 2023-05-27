#include"shell.h"
/**
 * _strlen - legnth
 * @s: in
 * Return: le
 */
int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (0);
	while (*s++)
		a++;
	return (a);
}
/**
 * _strcmp - two str
 * @a1: 1
 * @a2: 2
 * Return: neg or posi
 */
int _strcmp(char *a1, char *a2)
{
	while (*a1 && *a2)
	{
		if (a1 != a2)
			return (*a1 - *a2);
		a1++;
		a2++;
	}
	if (*a1 == *a2)
		return (0);
	else
		return (*a1 < *a2 ? -1 : 1);
}
/**
 * starts_with - starts with haystack
 * @hay: string to serch
 * @ned: to find
 * Return: address
 */
char *starts_with(const char *hay, const char *ned)
{
	while (*ned)
		if (*ned++ != *hay)
			return (NULL);
	return ((char *)hay);
}
/**
 * _strcat - concatenate
 * @dest: the destina
 * @src: the source
 * Return: adress
 */
char *_strcat(char *dest, char *src)
{
	char *r = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	return (r);
	}

