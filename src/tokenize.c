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

static int	_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (str1[i] != str2[i])
		return (1);
	return (0);
}

static int	_charcmp(char a, char b)
{
	if (a != b)
		return (1);
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

int	tokenize(t_token_struct **token_struct, t_lex_struct *lex_struct)
{
	int	i;

	i = 0;
	while (lex_struct->tokens[i])
	{
		if (!_strcmp(lex_struct->tokens[i], "|"))
			(*token_struct)[i].type = PIPE;
		else if (!_strcmp(lex_struct->tokens[i], ">"))
			(*token_struct)[i].type = REOUTPUT;
		else if (!_strcmp(lex_struct->tokens[i], ">>"))
			(*token_struct)[i].type = APPEND;
		else if (!_strcmp(lex_struct->tokens[i], "<"))
			(*token_struct)[i].type = REINPUT;
		else if (!_strcmp(lex_struct->tokens[i], "<<"))
			(*token_struct)[i].type = HDOC;
		else if (!_charcmp(lex_struct->tokens[i][0], '-'))
			(*token_struct)[i].type = OPTIONS;
		else if (!_charcmp(lex_struct->tokens[i][0], '\''))
			(*token_struct)[i].type = SINGLE_QUOTE;
		else if (!_charcmp(lex_struct->tokens[i][0], '"'))
			(*token_struct)[i].type = DOUBLE_QUOTE;
		else
			(*token_struct)[i].type = COMMAND;
		(*token_struct)[i].value = _strdup(lex_struct->tokens[i]);
		i++;
	}
	return (0);
}
