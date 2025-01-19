/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarck <lmarck@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:29:44 by lmarck            #+#    #+#             */
/*   Updated: 2025/01/18 17:29:48 by lmarck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	buf = 0;
	static int				bit = 0;
	static char				*str;

	(void)context;
	if (sig == SIGUSR2)
		bit++;
	else if (sig == SIGUSR1)
	{
		buf = buf | (1 << bit);
		bit++;
	}
	if (bit == 8)
	{
		str = treat_byte(buf, str, info);
		if (!buf)
			kill(info->si_pid, SIGUSR2);
		bit = 0;
		buf = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

char	*treat_byte(unsigned char buf, char *str, siginfo_t *info)
{
	(void)info;
	if (buf == 0)
	{
		ft_putstr(str);
		free(str);
		str = NULL;
	}
	else
	{
		if (str == NULL)
		{
			str = ft_calloc(1, 1);
			if (!str)
				return (NULL);
		}
		str = add_chr(buf, str);
	}
	return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

char	*add_chr(unsigned char buf, char *str)
{
	char	*nstr;
	int		i;

	i = 0;
	nstr = ft_calloc(ft_strlen(str) + 2, sizeof(char));
	if (!nstr)
		return (NULL);
	while (str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = buf;
	nstr[i + 1] = 0;
	free(str);
	return (nstr);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("server PID = %d\n", getpid());
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (68 > 67)
		pause();
	return (0);
}
