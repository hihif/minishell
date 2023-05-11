/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhihi <fhihi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 12:04:02 by eboulhou          #+#    #+#             */
/*   Updated: 2023/05/10 20:27:11 by fhihi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <curses.h>
#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

#define NX_PIPE
#define NX_OUT
#define PR_PIPE
#define PR_IN
#define PR_FRST

void rl_replace_line (const char *, int);

// imported from parser folder
typedef struct s_cmd
{
	char *cmd_path;
	char **cmd_args;
	int infile;
	int outfile;
	int key;
	char *str;
	char *exit_msg;
	int	exit_stat;
	int ctr_c;
	struct s_cmd *next;
	
}	t_cmd;

typedef struct s_cmd_list
{
	t_cmd	*current;
	struct s_cmd_list *next;
}	t_cmd_list;

typedef struct s_tokens
{
	int				pos;
	int				token_type;
	char			*token;
	struct s_tokens *prev;
	struct s_tokens *next;
}	t_tokens;

// -------- end of imports ////////

typedef struct s_comm
{
	int idx;
	char *com;
	int begin_com;
	char **flags;
	int red;
	char **infiles;
	char **heredoc;
	// int *in_her_ranks;
	char **outfiles;
	char **append;
	struct s_comm *next;
	struct s_comm *prev;
}t_comm;

typedef struct s_minishell
{
	t_cmd *comms;
	int *pipe;
	int pipecount;
	int pipe_nb;
	int child_nb;
	char **env;
	t_list **lenv;
	t_tokens **list;
	int g_exit;
}t_minishell;
///////////////////


// int g_exit = 0;
#include "EXEC/exec.h"
#include "parser/parse.h"
#include "./other_src/get_next_line.h"

void signal_handler(int sig);

#endif