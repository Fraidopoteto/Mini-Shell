/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:51:54 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/14 12:56:45 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

static int	_isspace(char a)
{
	if (a == ' ' || a == '\n' || a == '\t' || a == '\v' \
|| a == '\f' || a == '\r')
		return (1);
	return (0);
}

static void	_quote_size(char *input, int *j, int *token_size, char quote)
{
	(*j)++;
	while (input[(*j)] && input[(*j)] != quote)
		(*j)++;
	if (input[(*j)] == quote)
		(*j)++;
	(*token_size)++;
	while (input[(*j)] && _isspace(input[(*j)]))
		(*j)++;
	if (input[(*j)] == '"' || input[(*j)] == '\'')
		_quote_size(input , j, token_size, input[(*j)]);
}

static void	_operator_size(char *input, int *i, int *token_size, char operator)
{
	(*i)++;
	if (input[*i] && input[*i] == operator)
		(*i)++;
	(*token_size)++;
	while (input[*i] && _isspace(input[*i]))
		(*i)++;
	if (input[*i] == '<' || input[*i] == '>')
		_operator_size(input, i, token_size, input[*i]);
}

static int	_pipe_size(char *input, int *i, int *token_count)
{
	(*token_count)++;
	(*i)++;
	while (input[*i] && _isspace(input[*i]))
		(*i)++;
	if (input[*i] == '|')
	{
		if (_pipe_size(input, i, token_count))
			return (1);
	}
	return(0);
}

static int	_word_size(char *input, int *i, int *token_size)
{
	while (input[*i] && input[*i] != '<' && input[*i] != '>' && input[*i] != '|'
		&& input[*i] != '"' && input[*i] != '\'' && !_isspace(input[*i]))
		(*i)++;
	(*token_size)++;
	while (input[*i] && _isspace(input[*i]))
		(*i)++;
	if (input[*i] && input[*i] != '<' && input[*i] != '>' && input[*i] != '|'
		&& input[*i] != '"' && input[*i] != '\'' && !_isspace(input[*i]))
		_word_size(input, i, token_size);
	return(0);
}

static int	_get_token_size(char *input)
{
	int	i;
	int token_size;

	i = 0;
	token_size = 0;
	while (input[i])
	{
		while (input[i] && _isspace(input[i]))
			i++;
		if (input[i] && !_isspace(input[i]))
		{
			if (input[i] == '"' || input[i] == 39)
				_quote_size(input, &i, &token_size, input[i]);
			else if (input[i] == '>' || input[i] == '<')
				_operator_size(input, &i, &token_size, input[i]);
			else if (input[i] == '|')
				_pipe_size(input, &i, &token_size);
			else if (input[i] && input[i] != '<' && input[i] != '>'
			&& input[i] != '|' && input[i] != '"'
			&& input[i] != '\'' && !_isspace(input[i]))
				_word_size(input, &i, &token_size);
			else
				i++;
		}
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
