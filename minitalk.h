/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarck <lmarck@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:28:06 by lmarck            #+#    #+#             */
/*   Updated: 2025/01/18 17:29:20 by lmarck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stddef.h>
# include "ft_printf.h"
# include "libft.h"

int		send_chr(char c, int spid);
void	ft_putfstr(char *str);
char	*full_chr(unsigned char buf, char *str);
void	handler(int sig, siginfo_t *info, void *context);
void	print_bit(char c);
char	*treat_byte(unsigned char buf, char *str, siginfo_t *info);
char	*add_chr(unsigned char buf, char *str);
void	ft_putstr(char *str);
void	send_str(char *str, int spid);
void	client_ack_handler(int sig);

#endif
