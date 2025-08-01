/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:35:56 by joschmun          #+#    #+#             */
/*   Updated: 2025/07/16 13:03:48 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    cleanup(t_token_struct *token_struct, char **tokens, int *token_count)
{
    int i;

    i = 0;
    while (i < (*token_count))
    {
        free(token_struct[i].value);
        free(tokens[i]);
        i++;
    }
    free(token_struct);
    free(tokens);
}
