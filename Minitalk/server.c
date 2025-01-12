/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leo <leo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:07:04 by leo               #+#    #+#             */
/*   Updated: 2025/01/11 17:14:07 by leo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
void handler(int sig)
{
  sig = 1;
  sig++;
  write(1,"Nope\n", 5);
}

int main(void)
{
    struct sigaction sa;
    ft_printf("server PID = %d\n", getpid());
    sa.sa_handler = &handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa, NULL);
    while(68 > 67)
    {
        sleep(2);
        ft_printf("server PID = %d\n", getpid());
    }



    return(0);
}