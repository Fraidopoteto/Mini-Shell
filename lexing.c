/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:23:25 by joschmun          #+#    #+#             */
/*   Updated: 2025/07/11 14:23:25 by joschmun         ###   ########.fr       */
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

static int	_quotes_size(char *input, int position, int *token_size, char quote)
{
	int	i;

	i = position + 1;
	while (input[i] && input[i] != quote)
		i++;
	i++;
	(*token_size)++;
	while (input[i] && _isspace(input[i]))
		i++;
	if (input[i] == '"' || input[i] == 39)
		i = _quotes_size(input, i, token_size, input[i]);
	return (i);
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
			i = _quotes_size(input, i, &token_size, input[i]);
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

static int	_quotes(char *input, int position, int *token_count, char **tokens, char quote)
{
	int	i;

	i = position + 1;
	while (input[i] && input[i] != quote)
		i++;
	tokens[*token_count] = calloc((i - position + 1), 1);
	_strlcpy(tokens[*token_count], &input[position], (i - position + 1));
	(*token_count)++;
	i++;
	while (input[i] && _isspace(input[i]))
		i++;
	if (input[i] == '"' || input[i] == 39)
		i = _quotes(input, i, token_count, tokens, input[i]);
	return(i);
}

char	**lexing(char *input, int *token_count)
{
	int		i;
	int		j;
	char	**tokens;

	i = 0;
	j = 0;
	tokens = calloc((_get_token_size(input) + 1), sizeof(char *));
	while (input[i])
	{
		while (input[i] && _isspace(input[i]))
			i++;
		if (input[i] == '"' || input[i] == 39)
			i = _quotes(input, i, token_count, tokens, input[i]);
		if (!input[i])
			break ;
		j = i;
		while (input[j] && !_isspace(input[j]))
 			j++;
		tokens[*token_count] = calloc((j - i + 1), 1);
		_strlcpy(tokens[*token_count], &input[i], (j - i));
		(*token_count)++;
		i = j;
	}
	tokens[*token_count] = NULL;
	return (tokens);
}

// char	**lexing(char *input, int *token_count)
// {
// 	int		i;
// 	int		j;
// 	int		quotes_bool;
// 	char	**tokens;
// 	i = 0;
// 	j = 0;
// 	tokens = calloc((_get_token_size(input) + 1), sizeof(char *));
// 	while (input[i])
// 	{
// 		while (input[i] && _isspace(input[i]))
// 			i++;
// 		if (!input[i])
// 			break ; 
// 		j = i;
// 		while (input[j] && !_isspace(input[j]))
// 			j++;
// 		tokens[*token_count] = calloc((j - i + 1), 1);
// 		_strlcpy(tokens[*token_count], &input[i], (j - i));
// 		(*token_count)++;
// 		i = j;
// 	}
// 	tokens[*token_count] = NULL;
// 	return (tokens);
//} 