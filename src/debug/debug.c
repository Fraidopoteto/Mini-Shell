/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:22:22 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/26 17:32:20 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define END    "\033[0m"

static void    _print_indent(int level)
{
    int    i;

    i = 0;
    while (i < level)
    {
        printf("    ");
        ++i;
    }
}

void    _print_command(t_tree *root_p, int level)
{
    size_t    i;

    i = 0;
    _print_indent(level);
    printf("%s[program] %s\n%s", CYAN, root_p->argv[0], END);
    _print_indent(level);
    printf("%s[argv]\n%s", CYAN, END);
    while (root_p->argv[i])
    {
        _print_indent(level);
        printf("%s  %s\n%s", CYAN, root_p->argv[i], END);
        ++i;
    }
    // _print_indent(level);
    // _print_redir(&root_p->redir, level);
}

void    _print_ast(t_tree *root_p, int level)
{
    if (!root_p)
        return ;
    if (root_p->type == CMD)
    {
        if (root_p->argv && root_p->argv)
            _print_command(root_p, level);
        else
            printf("(Empty Command)\n");
    }
    else if (root_p->type == PIPE)
    {
        _print_indent(level);
        printf("[PIPE]\n");
        _print_indent(level);
        printf("├── LEFT:\n");
        _print_ast(root_p->branch->left_branch, level + 1);
        _print_indent(level);
        printf("└── RIGHT:\n");
        _print_ast(root_p->branch->right_branch, level + 1);
    }
}

void debug_info(t_token_struct **token_struct, t_lex_struct *lex_struct, t_tree *root_p)
{
    int i;

    i = 0;
    printf("\n\n===TOKEN DEBUG===\n");
    while (i < lex_struct->token_count)
    {
        printf("\nTOKEN: %i\n", i);
        printf("TYPE:  ");
        if ((*token_struct)[i].type == PIPE)
            printf("PIPE");
        else if ((*token_struct)[i].type == REINPUT)
            printf("REINPUT");
        else if ((*token_struct)[i].type == APPEND)
            printf("APPEND");
        else if ((*token_struct)[i].type == REOUTPUT)
            printf("REOUTPUT");
        else if ((*token_struct)[i].type == HDOC)
            printf("HDOC");
        else if ((*token_struct)[i].type == WORD)
            printf("WORD");
        else if ((*token_struct)[i].type == SINGLE_QUOTE)
            printf("SINGLE_QUOTE");
        else if ((*token_struct)[i].type == DOUBLE_QUOTE)
            printf("DOUBLE_QUOTE");
        printf("\nVALUE: %s\n", (*token_struct)[i].value);
        i++;
    }

    printf("\n\n===TREE DEBUG===\n\n");
    _print_ast(root_p, 0);
}
