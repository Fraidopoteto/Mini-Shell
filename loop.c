/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:38:16 by joschmun          #+#    #+#             */
/*   Updated: 2025/07/11 14:38:16 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_loop(void)
{
	char			*input;
	char			**tokens;
	int				token_count;
	t_token_struct	*token_struct = NULL;

	while (1)
	{
		token_count = 0;
		input = readline("minishell$ ");
		if (input == NULL)
		{
			printf("exit\n");
			break ;
		}
		tokens = lexing(input, &token_count);
		token_struct = tokenize(tokens, &token_count);
		debug_info(token_struct, &token_count);
		cleanup(token_struct, tokens, &token_count);
		free(input);
	}
	
}

