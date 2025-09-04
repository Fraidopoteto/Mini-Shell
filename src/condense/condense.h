/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condense.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun <joschmun@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:05:37 by joschmun          #+#    #+#             */
/*   Updated: 2025/09/03 10:31:18 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONDENSE_H
# define CONDENSE_H


# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "init.h"


int	condense(t_token_struct **token_struct, t_condense_struct **condense_struct, t_lex_struct *lex_struct);


#endif