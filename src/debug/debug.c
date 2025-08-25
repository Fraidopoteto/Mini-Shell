/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joschmun < joschmun@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:22:22 by joschmun          #+#    #+#             */
/*   Updated: 2025/08/25 20:42:23 by joschmun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"


void debug_info(t_token_struct **token_struct, t_lex_struct *lex_struct, t_tree ***tree, int *tree_size)
{
    int i;
    int root;

    i = 0;
    root = ((*tree_size) * 2) - 1; // Root-Index wie angegeben

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

    printf("\n\n===TREE DEBUG===\n");

    // Hilfsfunktion, um den Index eines Knotens im Baum-Array zu finden
    int find_index(t_tree *node, t_tree ***tree, int max_index)
    {
        if (node == NULL)
            return -1;
        int j = 0;
        while (j <= max_index)
        {
            if ((*tree)[j] == node)
                return j;
            j++;
        }
        return -1; // Knoten nicht gefunden
    }

    // Rekursive Funktion zum hierarchischen Drucken des Baums
    void print_tree(t_tree *node, int depth, t_tree ***tree, int max_index)
    {
        if (node == NULL)
        {
            for (int k = 0; k < depth; k++)
                printf("  ");
            printf("NULL\n");
            return;
        }

        int index = find_index(node, tree, max_index);
        if (index == -1)
        {
            for (int k = 0; k < depth; k++)
                printf("  ");
            printf("INVALID NODE (not in tree array)\n");
            return;
        }

        for (int k = 0; k < depth; k++)
            printf("  ");
        printf("TREE NODE: %i\n", index);

        for (int k = 0; k < depth; k++)
            printf("  ");
        printf("TYPE:  ");
        if (node->type == PIPE)
            printf("PIPE");
        else if (node->type == REINPUT)
            printf("REINPUT");
        else if (node->type == APPEND)
            printf("APPEND");
        else if (node->type == REOUTPUT)
            printf("REOUTPUT");
        else if (node->type == HDOC)
            printf("HDOC");
        else if (node->type == WORD)
            printf("WORD");
        else if (node->type == SINGLE_QUOTE)
            printf("SINGLE_QUOTE");
        else if (node->type == DOUBLE_QUOTE)
            printf("DOUBLE_QUOTE");
        else if (node->type == CMD)
            printf("CMD");
        else
            printf("UNKNOWN");
        printf("\n");

        for (int k = 0; k < depth; k++)
            printf("  ");
        printf("ARGV:  ");
        if (node->argv)
        {
            int j = 0;
            while (node->argv[j])
            {
                printf("%s ", node->argv[j]);
                j++;
            }
        }
        else
            printf("(null)");
        printf("\n");

        for (int k = 0; k < depth; k++)
            printf("  ");
        printf("BRANCH: ");
        if (node->branch)
        {
            int left_index = find_index(node->branch->left_branch, tree, max_index);
            int right_index = find_index(node->branch->right_branch, tree, max_index);

            printf("\n");
            for (int k = 0; k < depth; k++)
                printf("  ");
            printf("  Left Branch --> NODE: %i\n", left_index);
            print_tree(node->branch->left_branch, depth + 1, tree, max_index);

            for (int k = 0; k < depth; k++)
                printf("  ");
            printf("  Right Branch --> NODE: %i\n", right_index);
            print_tree(node->branch->right_branch, depth + 1, tree, max_index);
        }
        else
        {
            printf("NULL\n");
        }
        printf("\n");
    }

    // Vom Root-Knoten aus drucken
    printf("\nROOT NODE: %i\n", root);
    if (root >= 0 && (*tree) && (*tree)[root] != NULL)
    {
        print_tree((*tree)[root], 0, tree, root);
    }
    else
    {
        printf("  INVALID or NULL ROOT NODE\n");
    }
    printf("================\n\n");
}
