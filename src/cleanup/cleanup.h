/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:34:45 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/26 19:18:18 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "init.h"


void	cleanup(t_token_struct **token_struct, t_lex_struct *lex_struct, t_tree ***tree);


#endif
