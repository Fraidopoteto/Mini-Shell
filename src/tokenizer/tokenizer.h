/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:32:24 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/15 14:50:48 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "init.h"


int	tokenize(t_token_struct **token_struct, t_lex_struct *lex_struct);


#endif
