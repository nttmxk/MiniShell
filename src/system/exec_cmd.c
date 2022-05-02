/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanjeon <sanjeon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:31:19 by jinoh             #+#    #+#             */
/*   Updated: 2022/04/29 08:55:13 by sanjeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "run_cmd.h"
#include "../builtin/builtin.h"

void exec_cmd(char *argv[], char *envp[], char **path)
{
	printf("argv : %s\n", argv[0]);
	if (ft_strncmp("echo\0", argv[0], 5) == 0)
		ft_echo(argv);
	else if (ft_strncmp("cd\0", argv[0], 3) == 0)
		ft_cd(argv, envp);
	else if (ft_strncmp("pwd\0", argv[0], 4) == 0)
		ft_pwd();
	else if (ft_strncmp("export\0", argv[0], 7) == 0)
		ft_export(argv, envp);
	else if (ft_strncmp("unset\0", argv[0], 6) == 0)
		ft_unset(argv, envp);
	else if (ft_strncmp("env\0", argv[0], 4) == 0)
		ft_env(argv, envp);
	else if (ft_strncmp("exit\0", argv[0], 5) == 0)
		ft_exit(argv);
	else
	{
		argv[0] = cmd_connect_path(argv[0],	path);
		execve(argv[0], argv, envp);
	}
}