/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemple_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourgeo <hbourgeo@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:21:53 by hbourgeo          #+#    #+#             */
/*   Updated: 2022/03/24 14:40:38 by hbourgeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
	pid_t pid_fils;

	pid_fils = fork();
	if (pid_fils < 0)
	{
		printf("Error fork()");
		return(1);
	}
	if (pid_fils == 0)
	{
		printf("Enfant : PID = %ld, PPID = %ld \n", (long) getpid(), (long) getppid());
		return 0;
	} else 
	{
		printf("Parent : PID = %ld, PPID = %ld, PID_fils = %ld \n", (long)getpid(), (long) getppid(), (long)pid_fils);
		return 0;
	}
}
