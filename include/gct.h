/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:29:08 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/08 11:41:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GCT_H
# define GCT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_gct
{
	struct s_gct	*next;
	void			*ptr;
}	t_gct;

void	*gct_malloc(size_t size);
void	gct_cleanup(void);

#endif