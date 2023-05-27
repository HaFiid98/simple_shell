#include"shell.h"
/**
 * input_buf - buffer
 * @in: pram
 * @buf: add
 * @len: lenght
 * Return: bytes
 */
ssize_t input_buf(info_t *in, char **buf, size_t *len)
{
	ssize_t a = 0;
	size_t len_o = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		a = getline(buf, &len_o, stdin);
#else
		a = _getline(in, buf, &len_o);
#endif
		if (a > 0)
	{
		if ((*buf)[a - 1] == '\n')
		{
		(*buf)[a - 1] = '\0';
		a--;
		}
		in->linecount_flag = 1;
		remove_comments(*buf);
		build_history_list(in, *buf, in->hiscount++);
		/* if (_strch(*buf, ':')) is this a command chain? */
		{
			*len = a;
			in->cmd_buf = buf;
		}
	}
		}
	return (a);
}
/**
 * get_input - gets
 * @in: info
 * Return: bytes read
 */
ssize_t get_input(info_t *in)
{
	static char *buf;
	static size_t i, j, len;
	char **buf_c = &(in->arg), *p;
	ssize_t a = 0;

	_putchar(BUF_FLUSH);
	a = input_buf(in, &buf, &len);
	if (a == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;
		check_chain(in, buf, &j, i, len);
		while (j < len)
		{
			if (is_chain(in, buf, &j))
				break;
			j++;
		}
		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			in->cmd_buf_type = CMD_NORM;
		}
		*buf_c = p;
		return (_strlen(p));
	}
	*buf_c = buf;
	return (a);
}
/**
 * read_buf - read
 * @in: info
 * @buf: buffer
 * @i: size
 * Return: a
 */
ssize_t read_buf(info_t *in, char *buf, size_t *i)
{
	ssize_t a = 0;

	if (*i)
		return (0);
	a = read(in->readfd, buf, READ_BUF_SIZE);
	if (a >= 0)
		*i = a;
	return (a);
}
/**
 * _getline - gets the next line
 * @in: info
 * @ptr: adress
 * @length: leng
 * Return: a
 */
int _getline(info_t *in, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	ssize_t a = 0, b = 0;
	size_t k;
	char *p = NULL, *np = NULL, *c;

	p = *ptr;
	if (p && length)
		b = *length;
	if (i == len)
		i = len = 0;
	a = read_buf(in, buf, &len);
	if (a == -1 || (a == 0 && len == 0))
		return (-1);
	c = _strchr(buf + i, '\n');
	k = c ? 1 (unsigned int)(c - buf) : len;
	np = _realloc(p, b, b ? b + k : k + 1);
	if (!np)
		return (p ? free(p), -1 : -1);
	if (b)
		_strncat(np, buf + i, k - i);
	else
		_strncpy(np, buf + i, k - i + 1);
	b += k - i;
	i = k;
	p = np;

	if (length)
		*length = b;
	*ptr = p;
	return (b);
}
/**
 * sigintHandler - block ctrl c
 * @sig_num: sig
 * Return: none
 */
void sigintHandler(__attribute__((unsed))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
