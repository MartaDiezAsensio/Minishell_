
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>


#define MAX_INPUT_SIZE	1024


void	execute_command(char *command)
{
	//tokenize the line
	char	*token = strtok(command, " ");

	//check for built-in commands
	if(token != NULL)
	{
		if (strcmp(token, "echo") == 0)
			printf("%s\n", command + strlen("echo"));
		else if (strcmp(token, "cd") == 0)
		{
			token = strtok(NULL, " ");
			if (token)
			{
				if (chdir(token) != 0)
					perror("cd");
			}
			else
				fprintf(stderr, "cd: missing argument\n");
		}
	}
}

int main()
{
	char	*input;

	//setup history
	using_history();

	while (1)
	{
		input = readline("MyShll> ");

		//check for exit confitions
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break ;
		}

		//skip empty input
		if (strlen(input) > 0)
		{
			add_history(input);

			execute_command(input);
		}

		free(input);
	}

	clear_history();

	return(0);
}