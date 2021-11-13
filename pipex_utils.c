/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemma <tlemma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:07:16 by tlemma            #+#    #+#             */
/*   Updated: 2021/11/02 17:34:49 by tlemma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	check_cmds(void)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (g_pa.path1[i])
	{
		if (access(g_pa.path1[i], F_OK | X_OK) == 0)
			res = 1;
		i++;
	}
	if (!res)
		err(-1, 'x', g_pa.cmd1[0]);
	i = 0;
	res = 0;
	while (g_pa.path2[i])
	{
		if (access(g_pa.path2[i], F_OK | X_OK) == 0)
			res = 1;
		i++;
	}
	if (!res)
		err(-1, 'x', g_pa.cmd2[0]);
}

void	free_dp(char **i)
{
	while (*i)
	{
		free(*i);
		i++;
	}
}

void	free_args(void)
{
	free_dp(g_pa.cmd1);
	free_dp(g_pa.cmd2);
	free_dp(g_pa.path1);
	free_dp(g_pa.path2);
	free(g_pa.cmd1);
	free(g_pa.cmd2);
	free(g_pa.path1);
	free(g_pa.path2);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*ret;
	char	*cp_ret;
	char	*cp_s;

	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
		return (s2);
	ret = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	cp_ret = ret;
	cp_s = s1;
	while (*cp_s)
		*cp_ret++ = *cp_s++;
	cp_s = s2;
	while (*cp_s)
		*cp_ret++ = *cp_s++;
	*cp_ret = '\0';
	free(s1);
	return (ret);
}

char	**ft_getpath(char *keypairs[], char *cmd)
{
	int		i;
	char	*keypair;
	char	**path;

	i = 0;
	keypair = NULL;
	path = NULL;
	while (keypairs[i++])
	{
		keypair = ft_strnstr(keypairs[i], "PATH=/", 6);
		if (keypair != NULL)
		{
			keypair = ft_strnstr(keypair, "/", 6);
			path = ft_split(keypair, ':');
			break ;
		}
	}
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin2(path[i], "/");
		path[i] = ft_strjoin2(path[i], cmd);
		i++;
	}
	return (path);
}
