/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:22:22 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/14 14:11:34 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_info(t_token_struct **token_struct, t_lex_struct *lex_struct)
{
	int	i;

	i = 0;
    while (i < lex_struct->token_count)
	{
		printf("\n\nTOKEN: %i", i);
		printf("\nTYPE:  ");
		if ((*token_struct)[i].type == PIPE)
			printf("PIPE");
		else if ((*token_struct)[i].type == REINPUT)
			printf("REINPUT");
		else if ((*token_struct)[i].type == APPEND)
			printf("APPEND");
		else if ((*token_struct)[i].type == REOUTPUT)
			printf("REOUTPUT");
		else if ((*token_struct)[i].type == HDOC)
			printf("HDOC");
		else if ((*token_struct)[i].type == OPTIONS)
			printf("OPTIONS");
		else if ((*token_struct)[i].type == COMMAND)
			printf("COMMAND");
		else if ((*token_struct)[i].type == SINGLE_QUOTE)
			printf("SINGLE_QUOTE");
		else if ((*token_struct)[i].type == DOUBLE_QUOTE)
			printf("DOUBLE_QUOTE");
		printf("\nVALUE: %s\n\n", (*token_struct)[i].value);
		i++;
	}
}
