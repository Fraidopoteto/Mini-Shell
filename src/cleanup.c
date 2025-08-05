/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:35:56 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/05 16:27:41 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup(t_token_struct **token_struct, t_lex_struct *lex_struct)
{
	int	i;

	i = 0;
	while (i < lex_struct->token_count)
	{
		free((*token_struct)[i].value);
		free(lex_struct->tokens[i]);
		i++;
	}
	free(*token_struct);
	free(lex_struct->tokens);
	free(lex_struct->input);
}
