/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:57:14 by marvin            #+#    #+#             */
/*   Updated: 2022/06/17 14:06:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include<unistd.h>
# include<stdlib.h>
# include<limits.h>
# include<stdio.h>
# include<fcntl.h>
# include<pthread.h>
# include<sys/time.h>

typedef struct s_philo
{
	int				num_eats;
	long			last_eat;
	int				fork_l;
	int				fork_r;
	struct s_list	*d;
}	t_philo;

typedef struct s_list
{
	int				init_philo;
	int				stat;
	int				id;
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_think;
	int				philo_eats;
	t_philo			*philo;
	pthread_t		*thread;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	mutex_last_eat;
	pthread_mutex_t	mutex_stat;
	pthread_mutex_t	mutex_i;
	pthread_mutex_t	mutex_msg;
	pthread_mutex_t	mutex_fork;
	long			s_time;
}	t_list;

int		death_philo(t_list *d);
int		main(int argc, char **argv);
int		ft_atoi(const char *str);
int		check_eats(t_list *d);
int		create_thread(t_list *d);
int		create_mutex(t_list *d);
int		init_values(t_list *d);
long	calc_time(void);
void	w_status(char *s, t_list *d, int i);
void	ft_take_fork(t_list *d, int i);
void	ft_eat(t_list *d, int i);
void	ft_sleep(t_list *d, int i);
void	ft_usleep(int condition);
void	main_checker(t_list *d);
void	*philo_routine(void *f);

#endif
