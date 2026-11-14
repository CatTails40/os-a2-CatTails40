#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/pinfo.h"

int
main(void)
{
  struct pinfo info[64];
  int n;

  n = getpinfo(info, 64);
  printf("getpinfo returned %d\n", n);

  for (int i = 0; i < n; i++) {
    printf("pid=%d level=%d ticks=%d sched=%d ctime=%d name=%s\n",
           info[i].pid, info[i].level, info[i].runticks,
           info[i].nsched, info[i].ctime, info[i].name);
  }

  exit(0);
}

