#include <pthread.h>
#include <syslog.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

#define COURSE_NO     1
#define ASSIGNMENT_NO 1

static void *thread_func(void *arg)
{
    (void)arg;

    syslog(LOG_INFO,
           "[COURSE:%d][ASSIGNMENT:%d] Hello World from Thread!",
           COURSE_NO,
           ASSIGNMENT_NO);

    return NULL;
}

int main(void)
{
    pthread_t thread;

    openlog(NULL, LOG_PID, LOG_USER);

  struct utsname u;

    if (uname(&u) == 0)
    {
        syslog(LOG_INFO,
           "[COURSE:1][ASSIGNMENT:1] %s %s %s %s %s GNU/Linux",
           u.sysname,
           u.nodename,
           u.release,
           u.version,
           u.machine);
    }
    else
    {
        syslog(LOG_ERR, "[COURSE:1][ASSIGNMENT:1] uname failed");
    }
    syslog(LOG_INFO,
           "[COURSE:%d][ASSIGNMENT:%d] Hello World from Main!",
           COURSE_NO,
           ASSIGNMENT_NO);

    if (pthread_create(&thread, NULL, thread_func, NULL) != 0)
    {
        syslog(LOG_ERR, "pthread_create failed");
        closelog();
        return EXIT_FAILURE;
    }

    if (pthread_join(thread, NULL) != 0)
    {
        syslog(LOG_ERR, "pthread_join failed");
        closelog();
        return EXIT_FAILURE;
    }

    closelog();

    return EXIT_SUCCESS;
}
