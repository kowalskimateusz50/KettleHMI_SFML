
/* Some fixed defines */
/* Disable UART code */
#include<string>

#define DISABLE_UART

#define LOOPBACK_FORMAT "loopback: %s\r\n"
#define LOOPBACK_FORMAT_LEN strlen(LOOPBACK_FORMAT)
#define MAX_LOOPBACK_SIZE MAX_READ_SIZE + LOOPBACK_FORMAT_LEN

#define debug(x) std::cout << x << std::endl