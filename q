#include"shell.h"
/**
 * *_strncpy - copie a str
 * @dest: des
 * @src: the source
 * @n: alout of chars
 * Return: the concated strigs
 */
char *_strncpy(char *dest, *src, int n)
{
	int a, b;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < n - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < n)
	{
		b = a;
		while (b < n)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (s);
}
/**
 * *_strncat - concat
 * @dest: dest
 * @src: source
 * @n: n
 * Return: concat
 */
char *_strncat(char *dest, char *src, int n)
{
	int a, b = 0;
	char *s = dest;

	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < n)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < n)
		dest[a] = '\0';
	return (s);
}
/**
 * *_strchr - locate a character
 * @s: the strign
 * @c: char
 * Return: s
 */
char *_strchr(char *s, c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
