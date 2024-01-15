#Minishell

##Functions required

**readline**
To compile the program with the library: 
```bash
gcc your_program.c -lreadline -o your_program
```

**re_clear_history (readline)**

```C
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    // Add some commands to history
    add_history("command1");
    add_history("command2");

    // Clear the entire history
    rl_clear_history();

    return 0;
}
```

**rl_on_new_line (readline)**

**rl_replace_line (readline)**

```C
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char* prompt = "Enter a command: ";
    char* input;

    // Read a line of input
    input = readline(prompt);

    // Modify the input line (replace "old" with "new")
    rl_replace_line("new", 0);

    // Force redisplay to show the modified line
    rl_redisplay();

    // Add the modified line to history
    add_history(input);

    // Free the memory allocated by readline
    free(input);

    return 0;
}
```

**rl_redisplay (readline)**

**add_history**

**access**

**wait, waitpid, wait3, wait4**

**getcwd**

**chdir**

**stat, lstat, fstat**

**unlink**

**execve**

**dup, dup2**

**pipe**

**opendir**

**readdir**

**closedir**

**strerror, perror**

**isatty**

**ttyname**

**ttyslot**

**ioctl**

**getenv**

**tcsetattr**

**tcgetattr**

**tgetent**

**tgetflag, tgetnum, tgetstr, tgoto, tputs**


##Shell Checklist

[]. Display prompt

[]. Have a working directory

[]. Search and launsh the right executable (based on the path variable or using a relative or absolute path)

[]. Not using more than 1 global variable to indicate received signal. Signal handler will not access the main data structures

[]. Not interpret unclosed quotes or special characters like \ or ;

[]. Handle ' which will prevent the shell from interpreting the metacharacters in the quoted sequence

[].  Handle " which will prevent the shell from interpreting the metacharacters in the quoted sequence except for $

[].  Implement redirections
    []. < redirects inputs
    []. > redirects output
    []. << given a delimiter, then heredoc until the delimiter is seen
    []. >> redirect output in append mode

[]. Implement pipes

[]. Handle environment variables, which should expand to their values

[]. Handle $? which should expand to the exit status of the most recently executed foreground pipeline

[]. Handle signals (ctr-C. ctr-D, ctr-\)

[]. Implement builtins (eho (with option -n), cd, pwd, export, unset, env, exit)
