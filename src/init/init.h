/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:50:44 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/25 18:59:48 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>


typedef enum e_type {
	PIPE,
	REINPUT,
	APPEND,
	REOUTPUT,
	HDOC,
	WORD,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	CMD,
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

typedef struct s_tree {
	char			**argv;
	t_type			type;
	struct s_branch	*branch;
} t_tree;

typedef struct s_branch {
	t_tree	*left_branch;
	t_tree	*right_branch;
} t_branch;


int	init(t_token_struct **token_struct, t_lex_struct *lex_struct);
int	init_ast(t_tree ***tree, t_token_struct **token_struct, int token_count, int *tree_size);


#endif
