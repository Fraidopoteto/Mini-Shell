/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:36:17 by joschmun          #+#    #+#             */
/*   Updated: 2025/09/03 10:27:19 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "init.h"


void	debug_info(t_token_struct **token_struct, t_lex_struct *lex_struct, t_condense_struct **condense_struct, t_tree *root_p, int *condense_size);


#endif
