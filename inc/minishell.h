/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:24:20 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/05 18:59:58 by joschmun         ###   ########.fr       */
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
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
} t_type;

typedef struct token_struct {
	t_type	type;
	char	*value;
} t_token_struct;

typedef struct lex_struct {
	char	**tokens;
	int		token_count;
	char	*input;
} t_lex_struct;

//init.c
int				init(t_token_struct **token_struct, t_lex_struct *lex_struct);

//lexing.c
int				lexing(t_lex_struct *lex_struct);

//tokenize.c
int				tokenize(t_token_struct **token_struct, t_lex_struct *lex_struct);

//debug.c
void			debug_info(t_token_struct **token_struct, t_lex_struct *lex_struct);

//cleanup.c
void			cleanup(t_token_struct **token_struct, t_lex_struct *lex_struct);

//loop.c
int				shell_loop(void);

//error.c
int				error(char *str);


#endif
