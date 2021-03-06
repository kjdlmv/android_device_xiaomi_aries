#include <linux/input.h>
#include <fcntl.h>

#include "recovery_ui.h"
#include "common.h"
#include "extendedcommands.h"

static int write_int(char const* path, int value)
{
    int fd;
    static int already_warned = 0;

    fd = open(path, O_RDWR);
    if (fd >= 0) {
        char buffer[20];
        int bytes = sprintf(buffer, "%d\n", value);
        int amt = write(fd, buffer, bytes);
        close(fd);
        return amt == -1 ? -1 : 0;
    } else {
        if (already_warned == 0) {
            printf("write_int failed to open %s\n", path);
            already_warned = 1;
        }
        return -1;
    }
}

static int vibrate(int duration)
{
    int err = 0;
    err = write_int("/sys/class/timed_output/vibrator/enable", duration);
    return err;
}

int device_handle_key(int key_code, int visible) {
    switch (key_code) {
        case KEY_MENU:
        case KEY_HOME:
        case KEY_BACK:
            vibrate(30);
            break;
    }

    if (visible) {
        switch (key_code) {
            case KEY_CAPSLOCK:
            case KEY_DOWN:
            case KEY_VOLUMEDOWN:
            case KEY_MENU:
                return HIGHLIGHT_DOWN;

            case KEY_LEFTSHIFT:
            case KEY_UP:
            case KEY_VOLUMEUP:
            case KEY_HOME:
                return HIGHLIGHT_UP;

            case KEY_POWER:
            case KEY_LEFTBRACE:
            case KEY_ENTER:
            case BTN_MOUSE:
            case KEY_CAMERA:
            case KEY_F21:
            case KEY_SEND:
            case KEY_HOMEPAGE:
                return SELECT_ITEM;
            
            case KEY_END:
            case KEY_BACKSPACE:
            case KEY_SEARCH:
            case KEY_BACK:
                if (!ui_root_menu) {
                    return GO_BACK;
                }
        }
    }

    return NO_ACTION;
}
