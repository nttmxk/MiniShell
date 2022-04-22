/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:33:57 by sanjeon           #+#    #+#             */
/*   Updated: 2022/04/22 17:27:46 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	print_arg(t_arg *arg)
{
	t_cmd	*temp_cmd;

	temp_cmd = arg->c_t;
	while (temp_cmd != 0)
	{
		for (int i = 0; temp_cmd->cmd_param[i] != 0; i++)
			printf("cmd->cmd_param[%d] : \"%s\"\n", i, temp_cmd->cmd_param[i]);
		while (temp_cmd->redir != 0)
		{
			printf("file : %s, type : %d\n", temp_cmd->redir->filename, temp_cmd->redir->redir_type);
			temp_cmd->redir = temp_cmd->redir->next;
		}
		temp_cmd = temp_cmd->next;
	}
}

char	*app_str(char *dest, char *src)
{
	char	*output;

	output = 0;
	if (dest != 0)
	{
		if (src != 0)
			output = ft_strjoin(dest, src);
		else
			return (dest);
	}
	else
		output = ft_strdup(src);
	if (dest != 0)
		free(dest);
	if (src != 0)
		free(src);
	return (output);
}

char	**add_col(char **cmd, char *add)
{
	int		l;
	int		i;
	char	**temp;

	l = 0;
	while (cmd[l] != 0)
		l++;
	temp = (char **)ft_calloc(l + 2, sizeof(char *));
	if (temp == 0)
		return (0);
	i = -1;
	while (++i < l)
		temp[i] = cmd[i];
	temp[i] = add;
	free(cmd);
	return (temp);
}


int	pro_before_str(char **temp, char **line, int *i)
{
	*temp = app_str(*temp, ft_substr(*line, 0, *i));
	if (*temp == 0)
		return (0);
	(*line) = (*line) + *i;
	*i = 0;
	return (1);
}