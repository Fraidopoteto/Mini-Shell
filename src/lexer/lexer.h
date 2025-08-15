/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:39:03 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/15 14:50:16 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "error.h"
# include "init.h"


int	lexing(t_lex_struct *lex_struct);


#endif
