
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				cost_to_top;
	int				nearest;
	struct s_list	*next;
}					t_list;

/* Libft */
long				ft_atoi(const char *str);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list *lst);
void				ft_putchar_fd(char c, int fd, int *count);
void				ft_putnbr_fd(int n, int fd, int *count);
void				ft_putstr_fd(char *s, int fd, int *count);
size_t				ft_strlen(const char *input);
/* Printf */
int		ft_printf(const char *s, ...);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr_u(unsigned int n);
int		ft_puthex(unsigned long int n);
int		ft_puthexcaps(unsigned long int n);
int		ft_putptr(void *ptr);

void	swap(t_list **lst, char lstname);
void	push(t_list **src, t_list **dest, char lstname);
void	rotate(t_list **lst, char lstname);
void	reverse_rotate(t_list **lst, char lstname);
void    small_sort(t_list **a);
short int    is_sorted(t_list *lst);
void    set_index(t_list *lst);
int     find_median(t_list *a);
void    move_to_b(t_list **a, t_list **b);
void	set_cost(t_list *a, t_list *b);
void    move_to_a(t_list **a, t_list **b);
void	set_nearest(t_list *a, t_list *b);
t_list	*get_cheapest(t_list *a, t_list *b);
void    last_rotate(t_list **a);

#endif
