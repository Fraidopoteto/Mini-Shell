/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 12:47:08 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/15 14:50:35 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUN_H
# define RUN_H

# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <stdlib.h>
# include "debug.h"
# include "lexer.h"
# include "tokenizer.h"
# include "cleanup.h"
# include "init.h"


int	run(void);


#endif
