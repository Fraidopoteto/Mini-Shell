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
	int tree_size = 0;
	int	condense_size = 0;
	t_lex_struct		lex_struct;
	t_token_struct		*token_struct = NULL;
	t_condense_struct	*condense_struct = NULL;
	t_tree				**tree = NULL;
	t_tree				*root_p = NULL;
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
					if (!init_condense(&token_struct, &condense_struct, &lex_struct, &condense_size) && !condense(&token_struct, &condense_struct, &lex_struct))
					{
						if (!init_ast(&tree, &token_struct, lex_struct.token_count, &tree_size)
						&& !parsing(&tree, &token_struct, lex_struct.token_count, &root_p))
							debug_info(&token_struct, &lex_struct, &condense_struct, root_p, &condense_size);
						// execute_command(&token_struct, &lex_struct);
					}
				}
			}
		}
		cleanup(&token_struct, &lex_struct);
		clean_ast(&tree);
	}
	return (0);
}
