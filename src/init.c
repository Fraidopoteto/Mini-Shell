/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:51:54 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/05 16:54:07 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_isspace(char a)
{
	if (a == ' ' || a == '\n' || a == '\t' || a == '\v' \
|| a == '\f' || a == '\r')
		return (1);
	return (0);
}

static void	_quotes_size(char *input, int *i, int *token_size, char quote)
{
	int	j;

	j = (*i) + 1;
	while (input[j] && input[j] != quote)
		j++;
	if (input[j] == quote)
		j++;
	(*token_size)++;
	while (input[j] && _isspace(input[j]))
		j++;
	(*i) = j;
	if (input[j] == '"' || input[j] == 39)
		_quotes_size(input , i, token_size, input[j]);
}

static int	_get_token_size(char *input)
{
	int	i;
	int	j;
	int token_size;

	i = 0;
	j = 0;
	token_size = 0;
	while (input[i])
	{
		while (input[i] && _isspace(input[i]))
			i++;
		if (input[i] == '"' || input[i] == 39)
			_quotes_size(input, &i, &token_size, input[i]);
		if (!input[i])
			break ;
		j = i;
		while (input[j] && !_isspace(input[j]))
			j++;
		token_size++;
		i = j;
	}
	return(token_size);
}

int	init(t_token_struct **token_struct, t_lex_struct *lex_struct)
{
	lex_struct->token_count = 0;
	lex_struct->tokens = calloc((_get_token_size(lex_struct->input) + 1), sizeof(char *));
	if (!lex_struct->tokens)
		return (1);
	(*token_struct) = calloc((_get_token_size(lex_struct->input) + 1), sizeof(t_token_struct));
	if (!token_struct)
		return (1);
	return (0);
}
