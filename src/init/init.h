/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:50:44 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/15 14:50:03 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <unistd.h>
# include <stdio.h>
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


int				init(t_token_struct **token_struct, t_lex_struct *lex_struct);


#endif
