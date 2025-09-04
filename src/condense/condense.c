/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condense.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:13:50 by joschmun          #+#    #+#             */
/*   Updated: 2025/09/03 20:48:15 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "condense.h"

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


static char    *_trim_quote(const char *s1)
{
	char	*addycpy;
	size_t	i;

	addycpy = malloc(_strlen((char *)s1) - 1);
	i = 0;
	if (addycpy == NULL)
		return (NULL);
	else
	{
		while (i < ((size_t)_strlen((char *)s1)) - 2)
		{
			addycpy[i] = s1[i + 1];
			i++;
		}
		addycpy[i] = '\0';
	}
	return (addycpy);
}

int	condense(t_token_struct **token_struct, t_condense_struct **condense_struct, t_lex_struct *lex_struct)
{
    int i;
    int j;

    i = 0;
    j = 0;
     while (i < lex_struct->token_count)
    {
        if ((*token_struct)[i].type == WORD)
        {
            (*condense_struct)[j].value = _strdup((*token_struct)[i].value);
            i++;
            if ((*token_struct)[i].type == REINPUT)
                (*condense_struct)[j].type = REINPUT;
            else
            {
                (*condense_struct)[j].type = WORD;
                i--;
            }
        }
        else if ((*token_struct)[i].type == REOUTPUT)
        {
            (*condense_struct)[j].type = REOUTPUT;
            i++;
            (*condense_struct)[j].value = _strdup((*token_struct)[i].value);
        }
        else if ((*token_struct)[i].type == PIPE)
        {
            (*condense_struct)[j].type = PIPE;
            (*condense_struct)[j].value = _strdup((*token_struct)[i].value);
        }
        else if ((*token_struct)[i].type == HDOC)
        {
            (*condense_struct)[j].type = HDOC;
            (*condense_struct)[j].value = _strdup((*token_struct)[i].value);
        }
       else if ((*token_struct)[i].type == APPEND)
        {
            (*condense_struct)[j].type = APPEND;
            (*condense_struct)[j].value = _strdup((*token_struct)[i].value);
        }
        else if ((*token_struct)[i].type == SINGLE_QUOTE)
        {
            (*condense_struct)[j].type = SINGLE_QUOTE;
            (*condense_struct)[j].value = _trim_quote((*token_struct)[i].value);
        }
        else if ((*token_struct)[i].type == DOUBLE_QUOTE)
        {
            (*condense_struct)[j].type = DOUBLE_QUOTE;
            (*condense_struct)[j].value = _trim_quote((*token_struct)[i].value);
        }
        i++;
        j++;
    }
    return (0);
}