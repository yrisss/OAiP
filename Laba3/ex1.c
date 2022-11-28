#include <stdio.h>
#include <locale.h>
 
int main()
{
setlocale (LC_ALL, "");
    int m = 131, b = 160, s = 3000, v = 0;
    for (int km = 0; km < s/m; km++)
        for (int kb = 0; kb < s/b; kb++)
            if (km*m + kb*b == s) {
            	v = 1;
                printf("Можно"); }
                
if (v != 1) 
printf("Íåëüçÿ"); 
    return 0;
}
