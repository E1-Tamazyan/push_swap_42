/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:29:12 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/19 13:30:04 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack_node
{
	int					index;
	long long			nbr;
	struct s_stack_node	*next;
}	t_stack_node;

int				convert_verified(t_stack_node **stack_a, char **argv);
void			tiny_verif(char *s);
int				is_verified(char *str);
void			init_stack_a(t_stack_node **stack_a, char **argv);
int				check_list(t_stack_node **lst);
void			ft_lstiter(t_stack_node *lst);
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *new);
t_stack_node	*ft_lstnew(long long num);
long long		ft_atoi(const char *str);
char			**ft_split(char const *str);
t_stack_node	*ft_stack_end(t_stack_node *lst);
int				is_ascending(t_stack_node *lst);
int				is_dup(t_stack_node *lst);
int				ft_strlen(const char *src);
int				ft_dbstrlen(char **str);
char			*ft_substr(char const *s, int start, int len);
void			clear_str(char **arr);
void			clear_stack(t_stack_node *lst);
void			ft_lstclear(t_stack_node **lst);
long long		ft_lstsize(t_stack_node *lst);
t_stack_node	*ft_lstlast(t_stack_node *lst);
int				pa(t_stack_node **stack_a, t_stack_node **stack_b, int i);
int				pb(t_stack_node **stack_a, t_stack_node **stack_b, int i);
void			push(t_stack_node **stack_to, t_stack_node **stack_from);
void			swap(t_stack_node **stack);
int				sa(t_stack_node **stack_a, int i);
int				sb(t_stack_node **stack_b, int i);
int				ss(t_stack_node **stack_a, t_stack_node **stack_b, int i);
void			rotate(t_stack_node **stack);
int				ra(t_stack_node **stack_a, int i);
int				rb(t_stack_node **stack_b, int i);
int				rr(t_stack_node **stack_a, t_stack_node **stack_b, int i);
void			rerotate(t_stack_node **stack);
int				rra(t_stack_node **stack_a, int i);
int				rrb(t_stack_node **stack_b, int i);
int				rrr(t_stack_node **stack_a, t_stack_node **stack_b, int i);
void			set_index(t_stack_node **stack);
void			find_neccessary_sort(t_stack_node **a, t_stack_node **b);
int				get_position(t_stack_node **a, int res);
void			get_max_position(t_stack_node **a, long long *max);
void			sort_a3(t_stack_node **a, int len_b);
void			sort_b3(t_stack_node **b);
void			sort_5(t_stack_node **a, t_stack_node **b, long long nc);
void			sort_with_butterfly(t_stack_node **a, t_stack_node **b);
void			sort_b(t_stack_node **stack_a, t_stack_node **stack_b, int len);
void			sort_stack(t_stack_node **stack_a,
					t_stack_node **stack_b, int offset);
int				get_set(int size);
void			iter_for_atoi(const char *str, int *index, int *sign);
int				min_in_a(t_stack_node *a, int len);
void			simple_sort(t_stack_node **a, t_stack_node **b);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				do_sort(t_stack_node **a, t_stack_node **b);
int				do_swap(t_stack_node **a, t_stack_node **b, char *line);
int				do_push(t_stack_node **a, t_stack_node **b, char *line);
int				do_rotate(t_stack_node **a, t_stack_node **b, char *line);
char			*get_next_line(int fd);
char			*ft_readfd(int fd, char *buffer);
char			*ft_filtr(char *buffer);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *s1);
void			ft_strcpy(char *dst, const char *src);
size_t			ft_str_len(char *src);
int				check_stack(t_stack_node *stack);
char			*ft_find(char *s);
char			*ft_remainder(char *s);

#endif