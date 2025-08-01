/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:22:22 by joschmun          #+#    #+#             */
/*   Updated: 2025/07/16 13:40:39 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    debug_info(t_token_struct *token_struct, int *token_count)
{
    int i;

    i = 0;
    while (i < (*token_count))
	{
		printf("\n\nTOKEN: %i", i);
		printf("\nTYPE:  ");
		if (token_struct[i].type == PIPE)
			printf("PIPE");
		else if (token_struct[i].type == REINPUT)
			printf("REINPUT");
		else if (token_struct[i].type == APPEND)
			printf("APPEND");
		else if (token_struct[i].type == REOUTPUT)
			printf("REOUTPUT");
		else if (token_struct[i].type == HDOC)
			printf("HDOC");
		else if (token_struct[i].type == OPTIONS)
			printf("OPTIONS");
		else if (token_struct[i].type == COMMAND)
			printf("COMMAND");
		printf("\nVALUE: %s\n\n", token_struct[i].value);
		i++;
	}
}