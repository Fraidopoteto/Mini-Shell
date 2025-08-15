/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:23:25 by joschmun          #+#    #+#             */
/*   Updated: 2025/07/11 14:23:25 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "run.h"
#include "error.h"

static int	_isspace(char a)
{
	if (a == ' ' || a == '\n' || a == '\t' || a == '\v' \
|| a == '\f' || a == '\r')
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

static int	_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	src_len;
	size_t	i;

	src_len = _strlen((char *)src);
	i = 0;
	if (dst_size == 0)
		return (src_len);
	while (i < dst_size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

static int	_quote(t_lex_struct *lex_struct, int *i, char quote)
{
	int	j;

	j = *i;
	(*i)++;
	while (lex_struct->input[(*i)] && lex_struct->input[(*i)] != quote)
		(*i)++;
	if (lex_struct->input[(*i)] == quote)
		lex_struct->tokens[lex_struct->token_count] = calloc(((*i) - j + 1), 1);
	else
		return (1);
	if (!lex_struct->tokens)
		return(1);
	_strlcpy(lex_struct->tokens[lex_struct->token_count], &lex_struct->input[j], ((*i) - j + 1));
	lex_struct->token_count++;
	(*i)++;
	return(0);
}


static int	_operator(t_lex_struct *lex_struct, int *i, char operator)
{
	int	j;

	j = *i;
	(*i)++;
	if (lex_struct->input[*i] && lex_struct->input[*i] == operator)
		(*i)++;
	lex_struct->tokens[lex_struct->token_count] = calloc((((*i) - j) + 1), 1);
	if (!lex_struct->tokens)
		return(1);
	_strlcpy(lex_struct->tokens[lex_struct->token_count], &lex_struct->input[j], (*i - j));
	lex_struct->token_count++;
	return(0);
}

static int	_pipe(t_lex_struct *lex_struct, int *i)
{
	lex_struct->tokens[lex_struct->token_count] = calloc(1, 1);
	if (!lex_struct->tokens)
		return(1);
	_strlcpy(lex_struct->tokens[lex_struct->token_count], &lex_struct->input[*i], 1);
	lex_struct->token_count++;
	(*i)++;
	return(0);
}

static int	_word(t_lex_struct *lex_struct, int *i)
{
	int	j;

	j = (*i);
	while (lex_struct->input[*i] && lex_struct->input[*i] != '<' && lex_struct->input[*i] != '>'
		&& lex_struct->input[*i] != '|' && lex_struct->input[*i] != '"'
		&& lex_struct->input[*i] != '\'' && !_isspace(lex_struct->input[*i]))
		(*i)++;
	lex_struct->tokens[lex_struct->token_count] = calloc(((*i - j + 1)), 1);
	if (!lex_struct->tokens)
		return(1);
	_strlcpy(lex_struct->tokens[lex_struct->token_count], &lex_struct->input[j], (*i - j));
	lex_struct->token_count++;
	return(0);
}

int	lexing(t_lex_struct *lex_struct)
{
	int		i;

	i = 0;
	while (lex_struct->input[i])
	{
		while (lex_struct->input[i] && _isspace(lex_struct->input[i]))
			i++;
		if (lex_struct->input[i] && !_isspace(lex_struct->input[i]))
		{
			if (lex_struct->input[i] == '"' || lex_struct->input[i] == '\'')
			{
				if (_quote(lex_struct, &i, lex_struct->input[i]))
					return(error("syntax error: quotes\n"));
			}
			else if (lex_struct->input[i] == '<' || lex_struct->input[i] == '>')
				_operator(lex_struct, &i, lex_struct->input[i]);
			else if (lex_struct->input[i] == '|')
				_pipe(lex_struct, &i);
			else
				_word(lex_struct, &i);
		}
	}
	lex_struct->tokens[lex_struct->token_count] = NULL;
	return (0);
}
