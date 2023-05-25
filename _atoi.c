#include"shell.h"
/**
 * interactive - true if intrec
 * @in: info
 * Return: 1 if intera
 */
int interactive(info_t *in)
{
	return (isatty(STDIN_FILENO) && in->readfd <= 2);
}
/**
 * is_delim -check if char is delimeter
 * @c: the char chec
 * @del: delim s
 * Return: 1 or 0
 */
int is_delim(char c, char *del)
{
	while (*del)
		if (*del++ == c)
			return (1);
	return (0);
}
/**
 * _isalpha - check if alpha
 * @c: char
 * Return: 1 or 0
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - atoi
 * @s: var
 * Return: kdzz
 */
int _atoi(char *s)
{
	int i, si = 1, f = 0, o;
	unsigned int res = 0;

	for (i = 0; s[i] != '\0' && f != 2; i++)
	{
		if (s[i] == '-')
			si *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			f = 1;
			res *= 10;
			res += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
		if (si == -1)
			o = -res;
		else
			o = res;
	return (o);
	}
