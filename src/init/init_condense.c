/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_condense.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:15:30 by joschmun          #+#    #+#             */
/*   Updated: 2025/09/03 21:10:51 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int	init_condense(t_token_struct **token_struct, t_condense_struct **condense_struct, t_lex_struct *lex_struct, int *size)
{
    int i;

    i = 0;
    while (i < lex_struct->token_count)
    {
        (*size)++;
        i++;
        if ((*token_struct)[i].type == REOUTPUT)
            i++;
        else if ((*token_struct)[i].type == REINPUT)
            (*size)--;
    }
    (*condense_struct) = calloc((*size) + 1, sizeof(t_condense_struct));
    return(0);
}