#include"shell.h"
/**
 * _myen - pritn the enviro
 * @in: info
 * Return: 0
 */
int myen(info_t *in)
{
	print_list_str(in->env);
	return (0);
}
/**
 * geten - gets the value
 * @in: info
 * @name: name
 * Return: val
 */
char *geten(info_t *in, const char *name)
{
	list_t *node = in->env;
	char *o;

	while (node)
	{
		o = starts_with(node->str, name);
		if (o && *o)
			return (o);
		node = node->next;
	}
	return (NULL);
}
/**
 * _myseten - initialize new enviroment
 * @in: info
 * Return: 0
 */
int _myseten(info_t *in)
{
	if (in->argc != 3)
	{
		_eputs("incorrect number of arg\n");
		return (1);
	}
	if (_seten(in, info->argv[1], in->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunseten - remove
 * @in: info
 * Return: 0
 */
int _myunseten(info_t *in)
{
	int a;

	if (in->argc == 1)
	{
		_eputs("too few arguments.\n");
		return (1);
	}
	for (a = 1; a <= in->argc; a++)
		_unseten(in, in->argv[a]);
	return (0);
}
/**
 * pel - populite env
 * @in: info
 * Return: 0
 */
int pel(info_t *in)
{
	list_t *node = NULL;
	size_t a;

	for (a = 0; environ[a]; a++)
		add_node_end(&node, environ[i], 0);
	in->env = node;
	return (0);
}
