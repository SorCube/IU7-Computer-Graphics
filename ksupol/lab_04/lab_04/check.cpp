#include "check.h"
#include <QString>

int check_point(QString a)
{
    if (a[0] != '-' && (a[0] > '9' || a[0] < '0'))
        return -1;
    return 0;
}
