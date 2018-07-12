/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlauret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:24:54 by rlauret           #+#    #+#             */
/*   Updated: 2017/12/16 17:26:04 by rlauret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "get_next_line.h"
# include "libft.h"
# define BUFF_SIZE 16
# define MALL(x) if (!x) return (-1);

int		get_next_line(const int fd, char **line);
#endif
