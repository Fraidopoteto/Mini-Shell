/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:43:59 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/25 19:17:38 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	int _strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*_strdup(const char *s1)
{
	char	*addycpy;
	size_t	i;

	addycpy = malloc(_strlen((char *)s1) + 1);
	i = 0;
	if (addycpy == NULL)
		return (NULL);
	else
	{
		while (i < ((size_t)_strlen((char *)s1)))
		{
			addycpy[i] = s1[i];
			i++;
		}
		addycpy[i] = '\0';
	}
	return (addycpy);
}

int	parsing(t_tree ***tree, t_token_struct **token_struct, int token_count)
{
	int	i;
	int	y;
	int	j;
	int	tree_c;

	i = 0;
	y = 0;
	j = 0;
	tree_c = 0;
	while (i < token_count)
	{
		if ((*token_struct)[i].type == WORD)
		{
			j = i;
			while ((*token_struct)[j].type == WORD && i < token_count)
			{
				(*tree)[tree_c]->argv[y] = _strdup((*token_struct)[j].value);
				j++;
				y++;
			}
			(*tree)[tree_c]->type = CMD;
			(*tree)[tree_c]->branch = NULL;
			tree_c++;
		}
		else if ((*token_struct)[i].type == PIPE)
		{
			if (i == 0)
				return (1);
			(*tree)[tree_c]->type = PIPE;
			if (i == 1)
			{
				(*tree)[tree_c]->branch->left_branch = (*tree)[tree_c - 1];
				(*tree)[tree_c]->branch->right_branch = (*tree)[tree_c + 1];
			}
			else
			{
				(*tree)[tree_c]->branch->left_branch = (*tree)[tree_c - 2];
				(*tree)[tree_c]->branch->right_branch = (*tree)[tree_c + 1];
			}
			tree_c++;
		}
		y = 0;
		i++;
	}
	return (0);
}
