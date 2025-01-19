/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarck <lmarck@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:27:06 by lmarck            #+#    #+#             */
/*   Updated: 2025/01/18 17:30:36 by lmarck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile int	g_ack = 0;

int	main(int argc, char **argv)
{
	int					spid;
	struct sigaction	sa_client;

	g_ack = 0;
	sa_client.sa_handler = &client_ack_handler;
	sigemptyset(&sa_client.sa_mask);
	sa_client.sa_flags = 0;
	sigaction(SIGUSR1, &sa_client, NULL);
	sigaction(SIGUSR2, &sa_client, NULL);
	if (argc != 3)
		return (0);
	spid = ft_atoi(argv[1]);
	if (spid <= 0)
		return (0);
	send_str(argv[2], spid);
	return (0);
}

void	client_ack_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
	{
		write(1, "Message received \n", 19);
		g_ack = 1;
	}
}

void	send_str(char *str, int spid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_chr(str[i], spid);
		i++;
	}
	send_chr(0, spid);
}

int	send_chr(char c, int spid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack = 0;
		if ((c >> i) & 1)
			kill(spid, SIGUSR1);
		else
			kill(spid, SIGUSR2);
		i++;
		while (!g_ack)
			pause();
	}
	return (1);
}
