
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
	int				reverse;
	//int			cost_to_top
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
int					ft_printf(const char *s, ...);

void	swap(t_list **lst);
void	push(t_list **src, t_list **dest);
void	rotate_a(t_list **lst);
void	reverse_rotate_a(t_list **lst);
void    small_sort(t_list **a);
short int    is_sorted(t_list *lst);
void    set_index(t_list *lst);
int     find_median(t_list *a);

#endif
