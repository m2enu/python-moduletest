#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define N_BUF   2048

int create(char* bufs)
{
    int n = 0;
    for (int i=0; i<N_BUF; i++) {
        n += sprintf(bufs + n, "%02X", (i & 0xff));
    }
    return 0;
}

unsigned long hex2dec(char* s)
{
    return strtoul(s, NULL, 16);
}

void hex2decs(char* bufs, int* decs)
{
    int n = 0;
    char tmp[3];
    while(*(bufs + n) != '\0') {
        tmp[0] = *(bufs + n++);
        tmp[1] = *(bufs + n++);
        *decs = (int)hex2dec(tmp);
        decs++;
    }
}

void show(int* decs, int n)
{
    for (int i=0; i<n; i++) {
        printf("%02X", decs[i]);
    }
    printf("\n");
}

void showtime(struct timeval t1, struct timeval t2)
{
    float usec = (t2.tv_usec - t1.tv_usec) * 1.0E-6;
    float _sec = (t2.tv_sec  - t1.tv_sec );
    printf("%.3f sec\n", (_sec + usec));
}

int main(int argc, char** argv)
{
    char bufs[N_BUF*2];
    int decs[N_BUF];
    struct timeval t1, t2;

    create(bufs);

    gettimeofday(&t1, NULL);
    for (int i=0; i<4096; i++) {
        hex2decs(bufs, decs);
    }
    gettimeofday(&t2, NULL);

    show(decs, N_BUF);
    showtime(t1, t2);

    return 0;
}
