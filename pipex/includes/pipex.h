#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# include <stdlib.h>

# include <fcntl.h>

# include <sys/wait.h>

# include <string.h>

# include <stdio.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Numero de argumentos erroneo.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Comando no encontrado\n"

typedef struct s_pipex
{
  pid_t pid1;
  pid_t pid2;
  int tube[2];
  int infile;
  int outfile;
  char **paths;
  char **cmd_paths;
  char **cmd_args;
  char *cmd;
}t_pipex;

/* childs.c */
void first_child(t_pipex pipex, char **av, char **envp);
void second_child(t_pipex pipex, char **av, char **envp);

/* free.c */
void parent_free(t_pipex *pipex);
void child_free(t_pipex *pipex);

/* errors.c */
void msg_error(char *err);
int msg(char *err);

/* utils */
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *src);
char **ft_split(char const *s, char c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
size_t ft_strlen(const char *s);
#endif // !PIPEX_H
