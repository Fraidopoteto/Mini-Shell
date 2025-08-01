/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:29:01 by joschmun          #+#    #+#             */
/*   Updated: 2025/07/11 14:29:01 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

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

t_token_struct	*tokenize(char **tokens, int *token_count)
{
	int				i;
	t_token_struct	*token_struct;

	i = 0;
	token_struct = calloc((*token_count), sizeof(t_token_struct));
	while (tokens[i])
	{
		if (!_strcmp(tokens[i], "|"))
			token_struct[i].type = PIPE;
		else if (!_strcmp(tokens[i], ">"))
			token_struct[i].type = REOUTPUT;
		else if (!_strcmp(tokens[i], ">>"))
			token_struct[i].type = APPEND;
		else if (!_strcmp(tokens[i], "<"))
			token_struct[i].type = REINPUT;
		else if (!_strcmp(tokens[i], "<<"))
			token_struct[i].type = HDOC;
		else if (!_strcmp(tokens[i], "-"))
			token_struct[i].type = OPTIONS;
		else
			token_struct[i].type = COMMAND;
		token_struct[i].value = _strdup(tokens[i]);
		i++;
	}
	return (token_struct);
}
