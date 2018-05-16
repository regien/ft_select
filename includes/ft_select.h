/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalpart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 03:51:31 by gmalpart          #+#    #+#             */
/*   Updated: 2018/05/16 11:46:20 by regien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termcap.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include "libft.h"


# include <curses.h>
//# include <termios.h>
# include <unistd.h>
# include <term.h>
# include <signal.h>


typedef struct	s_total
{
//	char		*
	char		*width;
	char		*name_term;
//	struct		term;
}				t_total;


#endif
