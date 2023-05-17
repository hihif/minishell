/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_Utils4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:00:11 by fhihi             #+#    #+#             */
/*   Updated: 2023/05/17 16:38:01 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parse.h"

extern int g_exit;

void	del_emptyyy(t_tokens **list)
{
	t_tokens *head;

	head = *list;
	give_pos(list);
	while (head)
	{
		if (!ft_strncmp(head->token, "", 1))
		{
			head->token = ft_joinchar(head->token, 2);
			head = head->next;
		}
		else 
			head = head->next;
	}
}

void	free_2darrary(char **arr)
{
	int i;
	
	i = 0;
	while(arr && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	free_lincked_list(t_list *head)
{
	while(head)
	{
		ft_lstdelone(head, &free);
		head = head->next;		
	}
}

int	syntax_error(t_tokens **list)
{
	t_tokens *head;
	
	head = *list;
	give_pos(list);
	if ((head->token_type == 3 || head->token_type == 1) && !head->next)
	{
		ft_putstr_fd("minishell: syntax error\n", 2);
		return (1);
	}
	while (head)
	{
		if (head->token_type == 3 && !head->next)
		{
			ft_putstr_fd("minishell: syntax error\n", 2);
			return (1);
		}
		if (head->token_type == 1 && !head->next)
		{
			ft_putstr_fd("minishell: syntax error\n", 2);
			return (1);
		}
		if (head->token_type == 3 && head->next->token_type == 3)
		{
			ft_putstr_fd("minishell: syntax error\n", 2);
			return (1);			
		}
		if (head->token_type == 3 && head->next->token_type == 1)
		{
			ft_putstr_fd("minishell: syntax error\n", 2);
			return (1);
		}
		if (head->token_type == 1 && (head->pos == 1 || !head->next))
		{
			ft_putstr_fd("minishell: syntax error\n", 2);
			return (1);
		}
		if (head->token_type == 1 && head->next->token_type == 1)
		{
			ft_putstr_fd("minishell: syntax error\n", 2);
			return (1);
		}
		head = head->next;
	}
	return (0);
}

//this function checks my token Llist for the single and double redirections
void	check_double_red(t_tokens **list)
{
	t_tokens *head;
	char *tmp;

	head = *list;
	give_pos(list);
	while (head->next)
	{
		if (!ft_strncmp("<", head->token, 2) && !ft_strncmp("<", head->next->token, 2))
		{
			delete_node(list, head->next->pos);
			tmp = head->token;
			head->token = ft_strdup("<<");
			free(tmp);
		}
		else if (!ft_strncmp(">", head->token, 2) && !ft_strncmp(">", head->next->token, 2))
		{
			delete_node(list, head->next->pos);
			tmp = head->token;
			head->token = ft_strdup(">>");
			free(tmp);
		}
		else
			head = head->next;
	}
}

void	free_token(t_tokens **list)
{
	t_tokens *head;

	head = *list;
	while (head)
	{
		delete_node(list, head->pos);
		head = head->next;
	}
	free(*list);
}