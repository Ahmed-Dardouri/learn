#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#define LOOP        10

uint8_t main(void)
{
    uint32_t iteration = 0;
    uint32_t file = 0;

    file = open("/sys/class/gpio/gpio60/direction", O_RDWR);
    (void)write(file,"out",3);
    close(file);

    file = open("/sys/class/gpio/gpio60/value", O_WRONLY);
    for (iteration = 0; iteration < LOOP; iteration++)
    {
        (void)write(file, "1", 1);
        printf("\n 1 \n");
        sleep(1);
        (void)write(file, "0",1);
        printf("\n 0 \n");
        sleep(1);
    }
    close(file);
    printf("\n led blink done!! \n");
    return 0;

}
