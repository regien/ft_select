#include <termcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>


#include <curses.h>
//#include <termios.h>
#include <unistd.h>
#include <term.h>

/*
int		vaina(void)
{
	char			buffer[3];
	int				pendejada;

	pendejada = 1;
	while (pendejada)
	{
		read(0, buffer, 3);
		printf("readding = |%s|", buffer);
		if (buffer[0] == 27)
			printf("esto es una flecha\n");
//		else if (buffer[0] == 4)
		else if (buffer[0] == 4)
		{
			printf("Ctlr+d, STOP !\n");
			return (0);
		}
	}
}
*/

int	putpendejada(int c)
{
	printf("%c", c);
	return (1);
}

int		main(void)
{
	char			*name_term;
	struct termios	term;

	if (!(name_term = getenv("TERM")))
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &term) == -1)
		return (-1);

//	vaina();
	char			*res;

	if (!(res = tgetstr("cl", NULL)))
		return (-1);
	tputs(res, 0, putpendejada);
	return (0);
}

/*
** they are just a series of commands that outputs a special string
** that makes the terminal executes an action
*/


/*
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
*/
