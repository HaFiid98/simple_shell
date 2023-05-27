#include"shell.h"
/**
 * _myhistory - d
 * @in: in
 * Return: 0
 */
int _myhistory(info_t *in)
{
	print_list(in->history);
	return (0);
}
/**
 * unset_alias - sets alias to str
 * @in: inf
 * @st: lol
 * Return: 1 or 0
 */
int unset_alias(info_t *in, char *st)
{
	char *a, b;
	int r;

	a = _strchr(st, '-');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	r = delete_node_at_index(&(in->alias),
	get_node_index(in->alias, node_stars_with(in->alias, st, -1));
	*a = b;
	return (r);
	}
/**
 * set_alias - sets alias
 * @in: in
 * @st: str
 * Return: 1 or 0
 */
int set_alias(info_t *in, char *st)
{
	char *a;

	a = _strchr(st, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (unset_alias(in, st));
	unset_alias(in, st);
	return (add_node_end(&(in->alias), st, 0) == NULL);
}
/**
 * print_alias - print
 * @node: node
 * Return: 0 or 1
 */
int print_alias(list_t *node)
{
char *b = NULL;
char *a = NULL;

if (node)
{
	b = _strchr(node->str, '-');
	for (a = node->str; a <= b; a++)
		_putchar(*a);
	_putchar('\'');
	_puts(b + 1);
	_puts("'\n");
	return (0);
}
return (1);
}
/**
 * _myalias - mimics
 * @in: struct
 * Return: 0
 */
int _myalias(info_t *in)
{
	int a = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (in->argc == 1)
	{
		node = in->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 0; in->argv[a]; a++)
	{
		p = _strchr(in->argv[a], '=');
		if (p)
			set_alias(in, in->argv[a]);
		else
		{
		print_alias(node_stars_with(in->alias, in->argv[a], '='));
		}
	}
	return (0);
}

