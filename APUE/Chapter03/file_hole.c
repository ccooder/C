//
// Created by king on 7/21/18.
//
#include "apue/apue.h"
#include <fcntl.h>

int main(int argc, char const* argv[])
{
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    int fd;

    if ((fd = creat("/home/king/Desktop/file.hole", FILE_MODE)) < 0)
        err_sys("Can't create!");

    if (write(fd, buf1, 10) != 10)
        err_sys("buf1 write error!");
    /* offset now is 10 */

    if (lseek(fd, 16374, SEEK_CUR) == -1)
        err_sys("seek error!");
    /* offset now is 16384 */

    if (write(fd, buf2, 10) != 10)
        err_sys("buf2 write error");
    /* offset now is 16394 */
    err_msg("%d", fd);
    close(fd);

    if ((fd = creat("/home/king/Desktop/file.nohole", FILE_MODE)) < 0)
        err_sys("Can't create file.nohole!");
    err_msg("%d", fd);

    int i;
    for (i=0; i < 16394; ++i)
        write(fd, "n", 1);
    return 0;
}