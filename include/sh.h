/*
** sh.h for sh in /home/dejean_n/PSU_2015_42sh
**
** Made by nicolas dejean
** Login   <dejean_n@epitech.net>
**
** Started on  Wed May 18 16:40:57 2016 nicolas dejean
** Last update Sat Jun  4 07:17:15 2016 girard_z
*/


#ifndef SH_H_
# define SH_H_

# define QUIT		(1)

# define PWD_SIZE	(4096)
# define DEFAULT_PROMPT	"$"
# define DEFAULT_PATH	"/bin:/sbin:/usr/bin:/usr/sbin:/usr/heimdal/bin"


/*
**	FD DEFINES
*/

enum
  {
    FD_READ,
    FD_WRITE,
  };

/*
**	CMD DEFINES
*/

# define CD		"cd"
# define EXIT		"exit"
# define ECHO		"echo"
# define UNSETENV	"unsetenv"
# define SETENV		"setenv"
# define ENV		"env"

/*
**	ERROR DEFINES
*/

# define QUIT_RET	(51)
# define QUIT_ERR	"Error: syscall function failed\n"

# define SETENV_BEG_ERR	"setenv: Variable name must begin with a letter.\n"
# define SETENV_TOO_MANY_ARG "setenv: Too many arguments.\n"
# define SETENV_NAM_ERR	"setenv: Variable name must \
contain alphanumeric characters.\n"
# define UNSETENV_ERR	"unsetenv: Too few arguments.\n"
# define CD_FAILED	"cd: Can't change to home directory.\n"
# define CD_NB_ARG	"cd: Too many arguments.\n"
# define CD_WRONG_ARG	": Aucun fichier ou dossier de ce type.\n"
# define ACCESS_ERR	": Command not found.\n"
# define EXIT_BEG	"exit: Expression Syntax.\n"
# define EXIT_EXP	"exit: Badly formed number.\n"
# define ERR_PIPE	"Invalid null command.\n"
# define ERR_RD		"Missing name for redirect.\n"
# define AND_ERR_OP	"&: Error: Bad operator.\n"
# define CMD_LONG	": Nom de fichier trop long.\n"
# define ECHO_WRONG_VAR	": Undefined variable."
# define WRONG_OP	"Invalid null command.\n"
/*
**	RETURN DEFINES
*/

enum			e_ret_def
  {
    OK			= 42,
    KO			= 21,
  };

/*
**	LEXEME
*/

# define SMC		";"
# define OR		"||"
# define AND		"&&"
# define PIPE		"|"
# define RDL		"<"
# define RDR		">"
# define DRDL		"<<"
# define DRDR		">>"


enum			e_lexer_op
  {
    OP,
    OP_SMC,
    OP_OR,
    OP_AND,
    OP_PIPE,
    OP_RDL,
    OP_RDR,
    OP_DRDL,
    OP_DRDR,
    OP_NB,
    CMD,
    CMD_ARG,
    FILE_ARG
  };

/*
**	DATA STRUCT DEFINES
*/

typedef struct		s_cmd
{
  char			*arg;
  struct s_cmd		*next;
}			t_cmd;

typedef struct		s_lex
{
  int			type;
  char			*content;
  struct s_lex		*next;
}			t_lex;

typedef struct		s_tree
{
  t_lex			*lexer;
  struct s_tree		*left;
  struct s_tree		*right;
}			t_tree;

typedef struct		s_env
{
  char			*key;
  char			*value;
  struct s_env		*next;
}			t_env;

typedef struct		s_parse
{
  char			*op;
  int			type;
}			t_parse;

typedef struct		s_err_op
{
  int			op;
  int			(*fct_err_op)(t_lex *, int);
}			t_err_op;

typedef struct		s_exec_op
{
  char			*op;
  int			(*fct_op)(t_tree *, t_env **);
}			t_exec_op;

typedef struct		s_func
{
  char			*cmd;
  int			(*cmd_fct)(t_tree *, t_env **);
}			t_func;

typedef struct		s_sh
{
  int			return_value;
  t_env			*env_list;
  t_lex			*lexer;
  t_tree		*tree;
}			t_sh;

/*
**________________
**                |
**   PROTOTYPE    |
**________________|
*/

/*
**	PROMPT
*/

char			*prompt(t_env *);

/*
**ENV_MANAGEMENT
*/

int			list_env(t_env **, char **);
void			free_env(t_env **);

/*
**	SETENV AND UNSETENV
*/

int			exec_setenv(char *, char *, t_env **);
int			set_env(t_tree *, t_env **);
int			unset_env(t_tree *, t_env **);

/*
**	LEXEME
*/

int			rd_err(t_lex *, int);
int			and_err(t_lex *, int);
int			pipe_err(t_lex *, int);
int			smc_err(t_lex *, int);

int			place_lexer_cmd(t_lex **, const char *, int *, int);
void			precise_lexer_usability(t_lex **);
int			init_lexeme(t_lex **, char *);
void			free_lexem_delivery(t_lex **);
void			assemble_cmd(t_lex **);
int			verif_op(t_lex *);
int			lexeme_error_assemble(t_lex **);

/*
**	GRAMMAR
*/

int			start_grammar(t_sh *);
int			insert_left_stick(t_tree **, int);
int			insert_right_stick(t_tree **, int);
int			insert_actual_op(t_tree **, int);
char			*put_cmd_in_elem(t_tree *, int);
void			free_tree(t_tree **);

/*
**	EXECUTION
*/

int			hub_execution(t_tree *, t_env **);
int			execute_simple_cmd(t_tree *, t_env **);
int			execute_op(t_tree *, t_env **);

int			exe_cd(t_tree *, t_env **);
int			cd_dash(t_env **);
int			change_pwd_env(t_env **, char *);

int			exe_echo(t_tree *, t_env **);
int			exe_exit(t_tree *, t_env **);
int			exec_execve(t_tree *, t_env **);

int			exe_smc(t_tree *, t_env **);
int			exe_or(t_tree *, t_env **);
int			exe_and(t_tree *, t_env **);

/*
**	TOOLS
*/

char			**my_str_to_tab(const char *, char);
char			**env_to_tab(t_env *);
char			**lex_to_tab(t_lex *);

void			delete_space(char *, int *);
void			free_tab(char **);

char			*my_strcat(const char *, const char *, int);
int			my_strlen(const char *);
int			my_strcmp(char *, char *);
int			my_perror(char *, int);

void			show_line_env(t_env *, char *);
int			my_show_env_list(t_tree *, t_env **);
int			my_putstr(const char *);
int			my_putnbr(int);

#endif /* !SH_H_ */
