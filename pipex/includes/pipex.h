#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct	s_pipex
{
	char		**envp;
	char		*file1;
	char		*cmd1;
	char		*cmd2;
	char		*file2;
}				t_pipex;

int				ft_pipex(t_pipex *pipex);
int				ft_pipex_child(t_pipex *pipex, int *fd);
int				ft_pipex_parent(t_pipex *pipex, int *fd);

#endif