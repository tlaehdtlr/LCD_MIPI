#include "cli.h"

typedef struct
{
    char *cmd;                                          // Command
    void (*cmd_func)(uint8_t argc, void **argv);        // Function for command processing
    char *cmd_usage;                                    // Command usage
} cli_cmd_t;

static void help_func(uint8_t argc, void **argv);

const cli_cmd_t l_cli_cmds_t[] =
{
    {
        "help", help_func,
        "usage) \r\n \
                "
    },
    {
        (void *)0, (void *)0, (void *)0
    }
};

static void help_func(uint8_t argc, void **argv)
{
    // char *command = argv[0];
    // char *arg1 = argv[0 + strlen(command)];
    // char *arg2 = argv[0 + strlen(command) + strlen(arg1)];
    // char *arg3 = argv[0 + strlen(command) + strlen(arg1) + strlen(arg2)];

    if (argc == 1)
    {
        printf("\r\n ==== Command List ==== \r\n");
        for (int i = 0; l_cli_cmds_t[i].cmd_func != 0; i++)
        {
            printf("[%s] \r\n %s \r\n", l_cli_cmds_t[i].cmd, l_cli_cmds_t[i].cmd_usage);
        }
        return;
    }
}

static uint8_t shell_get_command_index(char *cmd_str)
{
    int i = 0;

    for (i = 0; l_cli_cmds_t[i].cmd_func != 0; i++)
    {
        if (strcmp(cmd_str, l_cli_cmds_t[i].cmd) == 0)
        {
            break;
        }
    }

    return i;
}

void cli_process(char* cmd)
{
    void *argv[128] = {0};
    int i = 0, idx = 0, argc = 0;
    // char *command, *arg1;
    char *command;
    uint8_t cmd_idx;

    char *ptr = strtok(cmd, " \r");

    while (ptr != NULL)
    {
        for (i = 0; i < strlen(ptr); i++)
            argv[idx++] = &ptr[i];

        ptr = strtok(NULL, " \r");
        argc++;
    }

    command = argv[0];
    // arg1 = argv[0 + strlen(command)];
    if (command)
    {
        cmd_idx = shell_get_command_index(command);
        if (l_cli_cmds_t[cmd_idx].cmd_func == 0)
        {
            printf("\r\n No command found \r\n");
            return;
        }
        l_cli_cmds_t[cmd_idx].cmd_func(argc, argv);
    }

    printf("\r\n");
}