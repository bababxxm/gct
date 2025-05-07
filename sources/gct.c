/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:45:11 by sklaokli          #+#    #+#             */
/*   Updated: 2025/05/08 00:25:23 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gct.h"

static t_gct	**gct_collector(void)
{
	static t_gct	*collector = NULL;

	return (&collector);
}

static t_gct	*gct_new_tracking(void *ptr)
{
	t_gct	*new;

	new = malloc(sizeof(t_gct));
	if (!new)
		return (NULL);
	new->ptr = ptr;
	new->next = NULL;
	return (new);
}

static void	gct_add_tracking(t_gct *new)
{
	t_gct	*last;
	t_gct	**gct;

	gct = gct_collector();
	if (!*gct && new)
		*gct = new;
	else if (*gct && new)
	{
		last = *gct;
		while (last && last->next)
			last = last->next;
		last->next = new;
	}
}

void	*gct_malloc(size_t size)
{
	void	*ptr;
	t_gct	*new;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc failed");
		gct_cleanup();
		exit(EXIT_FAILURE);
	}
	new = gct_new_tracking(ptr);
	if (!new)
	{
		free(ptr);
		perror("tracking node malloc failed");
		gct_cleanup();
		exit(EXIT_FAILURE);
	}
	gct_add_tracking(new);
	return (ptr);
}

void	gct_cleanup(void)
{
	t_gct	*tmp;
	t_gct	**collector;

	tmp = NULL;
	collector = gct_collector();
	while (*collector)
	{
		tmp = *collector;
		free(tmp->ptr);
		*collector = tmp->next;
		free(tmp);
	}
}
