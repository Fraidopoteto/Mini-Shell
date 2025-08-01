/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:24:20 by joschmun          #+#    #+#             */
/*   Updated: 2025/07/16 13:41:31 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <stdlib.h>


typedef enum e_type {
	PIPE,
	REINPUT,
	APPEND,
	REOUTPUT,
	HDOC,
	OPTIONS,
	COMMAND,
} t_type;

typedef struct token_struct {
	t_type	type;
	char	*value;
} t_token_struct;

//lexing.c
int				_strcmp(char *str1, char *str2);
char			**lexing(char *input, int *token_count);

//tokenize.c
t_token_struct	*tokenize(char **tokens, int *token_count);

//debug.c
void    		debug_info(t_token_struct *token_struct, int *token_count);

//cleanup.c
void    		cleanup(t_token_struct *token_struct, char** tokens, int *token_count);

//loop.c
void			shell_loop(void);


#endif
