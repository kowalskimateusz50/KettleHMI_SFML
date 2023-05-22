#include "uart.hpp"

int UartInit(struct UartDevice *dev, bool canonical)
{
    struct termios* tty; // Pointer for termios settings structure
    int fd;              // Status of opened filesystem
    int rc;              // Status of applied to termios settings

    /* Open terminal request */
    fd = open(dev->DevicePath, O_RDWR | O_NOCTTY);

    if (fd < 0)
    {
        printf("%s: failed to open UART device\r\n", __func__);
        return fd;
    }

    /* Allocating pointer on termios settings structure */
    tty = (termios*)malloc(sizeof(*tty));

    if (!tty)
    {
        return -ENOMEM;
    }

    memset(tty, 0, sizeof(*tty));

    /*Setting parameters UART to termios structure*/

    /* Set baud-rate.*/
    tty->c_cflag |= dev->BaudRate;

    /* Ignore framing and parity errors in input. */
    tty->c_iflag |= IGNPAR;

    /* Use 8-bit characters. This too may affect standard streams,
     * but any sane C library can deal with 8-bit characters. */
    tty->c_cflag |= CS8;

    /* Enable receiver. */
    tty->c_cflag |= CREAD;

    if (canonical)
    {
        /* Enable canonical mode.
         * This is the most important bit, as it enables line buffering etc. */
        tty->c_lflag |= ICANON;
    }
    else
    {
        /* To maintain best compatibility with normal behaviour of terminals,
         * we set TIME=0 and MAX=1 in noncanonical mode. This means that
         * read() will block until at least one byte is available. */
        tty->c_cc[VTIME] = 0;
        tty->c_cc[VMIN] = 1;
    }

    /* Flush port */
    tcflush(fd, TCIOFLUSH);

    /* Apply attributes */
    rc = tcsetattr(fd, TCSANOW, tty);
    if (rc)
    {
        printf("%s: failed to set attributes\r\n", __func__);
        return rc;
    }

    /*Write values to global structure */
    dev->fd = fd;
    dev->tty = tty;

    return 0;
}

int UartRead(struct UartDevice *dev, char *Buffer, size_t BufLen)
{
    int rc; 

    rc = read(dev->fd, Buffer, BufLen-1);
    if (rc < 0)
    {
		printf("%s: failed to read uart data\r\n", __func__);
		return rc;
	}
    Buffer[BufLen] = '\0';
    return rc;
}

int UartWrite(struct UartDevice *dev, char *Buffer, size_t BufLen)
{
    return write(dev->fd, Buffer, BufLen);
}

int UartWriteString(struct UartDevice *dev, char *Buffer)
{
    size_t StringLength = strlen(Buffer);

    return write(dev->fd, Buffer, StringLength);
}

int UartStop(struct UartDevice *dev)
{
    free(dev->tty);
}