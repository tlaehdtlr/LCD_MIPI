#include "cli.h"
#include "lcd_control.h"
#include <stdlib.h>

typedef struct
{
    char *cmd;                                          // Command
    void (*cmd_func)(uint8_t argc, void **argv);        // Function for command processing
    char *cmd_usage;                                    // Command usage
} cli_cmd_t;

static void help_func(uint8_t argc, void **argv);
static void led_control(uint8_t argc, void **argv);
static void lcd_control(uint8_t argc, void **argv);

const cli_cmd_t l_cli_cmds_t[] =
{
    {
        "help", help_func,
        "usage) \r\n \
                "
    },
    {
        "led", led_control,
        "usage) on/off [1~2]\r\n \
                "
    },
    {
        "lcd", lcd_control,
        "usage) err \r\n \
                \r\t stop/start \r\n \
                \r\t ch int [1,2] [r,g,b]\r\n \
                \r\t    ext [1~4] [r,g,b]\r\n \
                \r\t layer int/ext\r\n \
                "
    },
    {
        (void *)0, (void *)0, (void *)0
    }
};

static void lcd_control(uint8_t argc, void **argv)
{
    char *command = argv[0];
    char *arg1 = argv[0 + strlen(command)];
    char *arg2 = argv[0 + strlen(command) + strlen(arg1)];
    char *arg3 = argv[0 + strlen(command) + strlen(arg1) + strlen(arg2)];
    char *arg4 = argv[0 + strlen(command) + strlen(arg1) + strlen(arg2) + strlen(arg3)];

    if (argc == 1)
    {
        for (int i = 0; l_cli_cmds_t[i].cmd_func != 0; i++)
        {
            if (strcmp(l_cli_cmds_t[i].cmd, command) == 0)
            {
                printf("[%s] \r\n %s \r\n", l_cli_cmds_t[i].cmd, l_cli_cmds_t[i].cmd_usage);
                return;
            }
        }
    }
    else if (argc == 2)
    {
        if (strcmp(arg1, "err") == 0)
        {
            ltdc_get_err();
            return ;
        }
        else if (strcmp(arg1, "start") == 0)
        {
            dsi_start(true);
            return ;
        }
        else if (strcmp(arg1, "stop") == 0)
        {
            dsi_start(false);
            return ;
        }

    }
    else if (argc == 3)
    {
        if (strcmp(arg1, "layer") == 0)
        {
            if (strcmp(arg2, "int") == 0)
            {
                ltdc_change_layer(0, LAYER0_ADDRESS);
                return;
            }
            else if (strcmp(arg2, "ext") == 0)
            {
                ltdc_change_layer(0, SDRAM_ADDRESS);
                return;
            }
        }

    }
    else if (argc == 5)
    {
        if (strcmp(arg1, "ch") == 0)
        {
            uint8_t sector = 0;
            if (strcmp(arg2, "int") == 0)
            {
                sector = atoi(arg3) - 1;
                if (sector <= 1)
                {
                    if (strcmp(arg4, "r") == 0)
                    {
                        lcd_control_change_flash(LCD_COLOR_RED, sector);
                        return ;
                    }
                    else if (strcmp(arg4, "g") == 0)
                    {
                        lcd_control_change_flash(LCD_COLOR_GREEN, sector);
                        return ;
                    }
                    else if (strcmp(arg4, "b") == 0)
                    {
                        lcd_control_change_flash(LCD_COLOR_BLUE, sector);
                        return ;
                    }
                }
            }
            else if (strcmp(arg2, "ext") == 0)
            {
                sector = atoi(arg3) - 1;
                if (sector <= 3)
                {
                    if (strcmp(arg4, "r") == 0)
                    {
                        lcd_control_change_sdram(LCD_COLOR_RED, sector);
                        return ;
                    }
                    else if (strcmp(arg4, "g") == 0)
                    {
                        lcd_control_change_sdram(LCD_COLOR_GREEN, sector);
                        return ;
                    }
                    else if (strcmp(arg4, "b") == 0)
                    {
                        lcd_control_change_sdram(LCD_COLOR_BLUE, sector);
                        return ;
                    }
                }
                
            }
        }
    }
    printf("\r\nNot registered command \r\n");
}

static void led_control(uint8_t argc, void **argv)
{
    char *command = argv[0];
    char *arg1 = argv[0 + strlen(command)];
    char *arg2 = argv[0 + strlen(command) + strlen(arg1)];

    if (argc == 1)
    {
        for (int i = 0; l_cli_cmds_t[i].cmd_func != 0; i++)
        {
            if (strcmp(l_cli_cmds_t[i].cmd, command) == 0)
            {
                printf("[%s] \r\n %s \r\n", l_cli_cmds_t[i].cmd, l_cli_cmds_t[i].cmd_usage);
                return;
            }
        }
    }
    else if (argc == 3)
    {
        if (strcmp(arg1, "on") == 0)
        {
            if (strcmp(arg2, "1") == 0)
            {
                HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
                return;
            }
            else if (strcmp(arg2, "2") == 0)
            {
                HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
                return;
            }
        }
        else if (strcmp(arg1, "off") == 0)
        {
            if (strcmp(arg2, "1") == 0)
            {
                HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
                return;
            }
            else if (strcmp(arg2, "2") == 0)
            {
                HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
                return;
            }
        }
    }
    printf("\r\nNot registered command \r\n");
    
}

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