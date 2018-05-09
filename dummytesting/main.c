#include <termcap.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

/*
** 0 1 2 - you know them
*/

int		main(void)
{
	char	*ret;
	char	tty[40];

	
	if (!(ret = ttyname(STDIN_FILENO)))
		return (0);
	else
	{
		strcpy(tty, ret);
		printf("function = |%s| \n", ret);
		printf("tty = |%s| \n", tty);
	}

	printf("tty value or stuff like that  = |%d|\n", ttyslot());
	printf("-----------PRINTING ENV VARIABLES-----------\n");
	printf("env PATH = |%s|\n", getenv("PATH"));
	printf("env HOME = |%s|\n", getenv("HOME"));
	printf("env ROOT = |%s|\n", getenv("ROOT"));

	struct winsize w;
	
	// basically taking the window size from the output
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	
	printf("lines: %d\n", w.ws_row);
	printf("columns:  %d\n", w.ws_col);
	printf("pixelsx:  %d\n", w.ws_xpixel);
	printf("pixelsy:  %d\n", w.ws_ypixel);
	return 0;
}
