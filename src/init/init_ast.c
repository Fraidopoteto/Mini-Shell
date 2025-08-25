/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:52:06 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/25 19:14:28 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	init_ast(t_tree ***tree, t_token_struct **token_struct, int token_count, int *tree_size)
{
	int	i;
	int	j;
	int	y;

	i = 0;
	j = 0;
	y = 0;
	while (i < token_count)
	{
		if ((*token_struct)[i].type == PIPE)
			(*tree_size)++;
		i++;
	}
	(*tree) = calloc((((*tree_size) * 2) + 2), sizeof(t_tree *));
	i = 0;
	if (!tree)
		return(1);
	while (i < (((*tree_size) * 2) + 1))
	{
		(*tree)[i] = calloc(1, sizeof(t_tree));
		if (!(*tree)[i])
			return (1);
		i++;
	}
	i = 0;
	while (i < token_count)
	{
		if ((*token_struct)[i].type == PIPE)
		{
			(*tree)[j]->argv = calloc((y + 1), sizeof(char *));
			j++;
			(*tree)[j]->branch = calloc(1, sizeof(t_branch));
			j++;
			y = 0;
		}
		y++;
		i++;
	}
	(*tree)[j]->argv = calloc((y + 1), sizeof(char *));
	return (0);
}
