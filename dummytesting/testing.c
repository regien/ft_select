#include <termcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ioctl.h>


#include <termios.h>
#include <unistd.h>
#include <term.h>


int		main(void)
{
	char			*name_term;
	struct termios	term;

	if (!(name_term = getenv("TERM")))
		return (-1);
	if (tgetent(NULL, &name_term) == ERR)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);

	vaina();
	return (0);
}

int		vaina(void)
{
	char			buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
	}
}


/*
	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	// On applique les changements :
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
*/
