#include"shell.h"
/**
 * main - entry poin
 * @ac: arg
 * @av: arg vect
 * Return: 0
 */
int main(int ac, char av)
{
	int in[] = { INFO_INIT };
	int f = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (f)
			: "r" (f));
	if (ac == 2)
	{
		f = open(av[1], O_RDONLY);
		if (f == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Cant't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		in->readfd = f;
	}
	pel(in);
	read_history(in);
	hsh(in, av);
	return (EXIT_SUCCESS);
}
