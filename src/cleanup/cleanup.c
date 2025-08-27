/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:35:56 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/27 15:54:45 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

int		_tree_size(t_tree ***tree)
{
	int	i;

	i = 0;
	while ((*tree)[i])
		i++;
	return (i);
}

void	clean_ast(t_tree ***tree)
{
	int	i;
	int	j;
	int	tree_size;

	i = 0;
	j = 0;
	tree_size = _tree_size(tree);
	while (i < tree_size)
	{
		free((*tree)[i]->branch);
		while ((*tree)[i]->argv && (*tree)[i]->argv[j])
		{
			free((*tree)[i]->argv[j]);
			j++;
		}
		free((*tree)[i]->argv);
		i++;
		j = 0;
	}
	i = 0;
	while (i < tree_size)
	{
		free((*tree)[i]);
		i++;
	}
	free(*tree);
}

void	cleanup(t_token_struct **token_struct, t_lex_struct *lex_struct)
{
	int	i;

	i = 0;
	while (i < lex_struct->token_count)
	{
		free((*token_struct)[i].value);
		free(lex_struct->tokens[i]);
		i++;
	}
	free(*token_struct);
	free(lex_struct->tokens);
	free(lex_struct->input);
}
