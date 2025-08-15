/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:38:16 by joschmun          #+#    #+#             */
/*   Updated: 2025/07/11 14:38:16 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "run.h"

// int	execute_command(t_token_struct **token_struct, t_lex_struct *lex_struct)
// {
// 	int	i;

// 	i = 0;
// 	while (i < lex_struct->token_count)
// 	{
// 		if ((*token_struct)[i].type == HDOC)
// 			hdoc(&token_struct, &lex_struct);
// 		i++;
// 	}
// }

int	run()
{
	t_token_struct	*token_struct = NULL;
	t_lex_struct	lex_struct;
	while (1)
	{
		lex_struct.input = 0;
		lex_struct.input = readline("minishell$ ");
		if (lex_struct.input == NULL)
		{
			printf("exit\n");
			break ;
		}
		if (!init(&token_struct, &lex_struct))
		{
			if (!lexing(&lex_struct))
			{
				if (!tokenize(&token_struct , &lex_struct))
				{
					debug_info(&token_struct, &lex_struct);
					// execute_command(&token_struct, &lex_struct);
				}
			}
		}
		cleanup(&token_struct, &lex_struct);
	}
	return (0);
}
