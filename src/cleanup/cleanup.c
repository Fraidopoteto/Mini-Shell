/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:35:56 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/26 19:17:57 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"

int		_tree_size(t_tree ****tree)
{
	int	i;

	i = 0;
	while ((*tree)[i])
		i++;
	return (i);
}

void	cleanup(t_token_struct **token_struct, t_lex_struct *lex_struct, t_tree ***tree)
{
	int	i;
	int	tree_size;

	i = 0;
	tree_size = _tree_size(&tree);
	while (i < lex_struct->token_count)
	{
		free((*token_struct)[i].value);
		free(lex_struct->tokens[i]);
		i++;
	}
	free(*token_struct);
	free(lex_struct->tokens);
	free(lex_struct->input);
	i = 0;
	while (i < tree_size)
	{
		free((*tree)[i]->branch);
		free((*tree)[i]->argv);
		i++;
	}
	i = 0;
	while (i < tree_size)
	{
		free((*tree)[i]);
		i++;
	}
	free(*tree);
}
