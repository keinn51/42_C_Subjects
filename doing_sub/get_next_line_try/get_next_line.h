/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:10:31 by kyungsle          #+#    #+#             */
/*   Updated: 2021/11/22 11:04:32 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int			lst_fd;
	char		*content;
	struct s_list	*next;
}	t_list;

#endif