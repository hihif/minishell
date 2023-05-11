/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboulhou <eboulhou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:14:20 by eboulhou          #+#    #+#             */
/*   Updated: 2023/05/11 17:25:32 by eboulhou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

extern int g_exit;
int	export_error(char *s)
{
	if (ft_isdigit(s[0]))
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	return (0);
}
int ft_export(t_minishell msh , t_cmd *cmd)
{
    t_list *tmp;
	int i;

	i = 1;
	while (cmd->cmd_args[i])
	{
    	tmp = *msh.lenv;

		if (!export_error(cmd->cmd_args[i]))
		{		
    		while(tmp && tmp->content)
    		{
    		   	if(!ft_strncmp(cmd->cmd_args[i], tmp->content, ft_strnstr_mod(tmp->content, "=")))
    		   	{    
    		   	     tmp->content = cmd->cmd_args[i];
					 break ;
    		   	}
    		   	tmp = tmp->next;
    		}
			if(!tmp || !tmp->content)
			{
				ft_lstlast(*msh.lenv)->content = cmd->cmd_args[i];
				ft_lstadd_back(msh.lenv, ft_lstnew(NULL));
			}
		}
		i++;
	}

    
    return 1;

	return 0;
}
int ft_cd(t_cmd *cmd, t_minishell *msh)
{
    if(cmd->cmd_args[1])
        chdir(cmd->cmd_args[1]);
    else
        chdir(get_from_env(*msh->lenv, "HOME=", 5)+5);
    return 0;
}

int ft_echo(t_cmd *cmd)
{
    char **to_print;

    to_print = cmd->cmd_args;
    // puts("jdkjkdjk");
    to_print++;
    while(*to_print)
    {
            printf("%s", *to_print);
            to_print++;
    }
    printf("\n");
    return 0;
}
int ft_pwd()
{
    printf("%s\n", getcwd(NULL, 0));
    return 0;
}
void ft_env_cmd(t_minishell *msh)
{
    t_list *tmp;
    
    tmp = *msh->lenv;
    while(tmp && tmp->content)
    {
        printf("%s\n", tmp->content);
        tmp = tmp->next;
    }
}

void ft_unset(t_minishell *msh, t_cmd *cmd)
{
    t_list *tmp;
    t_list *prv;
    
    prv = NULL;
    tmp = *msh->lenv;
    char *arg;
    if(cmd->cmd_args[1])
    {
        arg = cmd->cmd_args[1];
        while(tmp && tmp->content)
        {
            int i = 1;
            if(!ft_strncmp(tmp->content, arg, ft_strlen(arg)-1))
            {
                prv->next = tmp->next;
                free(tmp->content);
                free(tmp);
                break;
            }
            prv = tmp;
            tmp = tmp->next;
        }
    }
}

int  check_builtis(t_cmd *cmd , t_minishell *msh)
{
    // puts(cmd->cmd_path);
    // puts("test");
	if(!cmd->cmd_path)
		return (0);
	if(!ft_strncmp(cmd->cmd_path, "export", 7))
	{
		ft_export(*msh, cmd);
        return 1;
	}
	if(!ft_strncmp(cmd->cmd_path, "unset", 6))
	{
		ft_unset(msh, cmd);
        return 1;
	}
	if(!ft_strncmp(cmd->cmd_path, "echo", 5))
	{
		ft_echo(cmd);
        return 1;
	}
	if(!ft_strncmp(cmd->cmd_path, "cd", 3))
	{
		ft_cd(cmd , msh);
        return 1;
	}
	if(!ft_strncmp(cmd->cmd_path, "pwd", 4))
	{
		ft_pwd();
        return 1;
	}
	if(!ft_strncmp(cmd->cmd_path, "env", 4))
	{
		ft_env_cmd(msh);
        return 1;
	}
	if(!ft_strncmp(cmd->cmd_path, "exit", 5))
	{
		exit(0);
        return 1;
	}
    
    return 0;
}