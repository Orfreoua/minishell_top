
#include "../headers/minishell.h"

void	free_pipe(t_exec *exec)
{
	free(exec->pipe.cmd);
		exec->pipe.cmd = NULL;
	free(exec->pipe.path_cmd);
		exec->pipe.path_cmd = NULL;
	free_tab(exec->pipe.cmd_splited);
}

void	free_heredoc(t_exec *exec)
{
	int	i;

	if (!exec->hd.nb)
		return ;
	i = 0;
	while (i < exec->hd.nb)
	{
		close(exec->hd.tab_fd[i]);
		i++;
	}
	free(exec->hd.tab_fd);
	free_tab(exec->hd.tab_of_name_file);
	free_tab(exec->hd.tab_exit_code);
	exec->hd.nb = 0;
}