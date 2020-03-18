#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
char compliments[13][100] = {{"You are the best!\n"}, {"You are the most powerful person that I know.\n"},
    {"You can do anything you want!\n"}, {"Honestly, i'm jealous of you. Because you do best at EVERYTHING!!\n"},
    {"You are the king of the world.\n"}, {"I wish i could be you!\n"},
    {"You are handsome.. or you must be beautiful..\n"}, {"You are really smart!\n"},
    {"Hey, don't be intimidiated. You know you can do anything?\n"},
    {"I know a guy who do everything well, and his name is"},
    {"You are always right.\n"}, {"You look taller than I thought? I'm 100% sure.\n"},
    {"Everyone loves you, even me!\n"}};
int main(void)
{
    srand(time(NULL));
    char name[30];
    printf("What is your name?\n");
    scanf("%s", name);
    sleep(1.5);
    printf("Okay %s. How many times do you want to hear compliments? \n", name);
    int complimentTimes = 0;
    scanf("%d", &complimentTimes);
    
    while(complimentTimes > 100)
    {
        printf("Too much times.. I can give you less than 100 times :p\n");
        printf("Write me again how many times do you want to hear compliments?\n");
        scanf("%d", &complimentTimes);
    }
    printf("Okay.. I'll tell you %d times to cheering you up!\n", complimentTimes);
    sleep(2);    
    int i, index, recent;
    index = 0; recent = 0;
    for(i = 0; i < complimentTimes; i++)
    {
        while(recent == index)
        {
            index = rand() % 13;
        }
       
        if(index == 9)
        {
            printf("%s %s!\n", compliments[index], name);
        }
        else
        {
            printf("%s", compliments[index]);
        }
        recent = index;
        sleep(3.5);
    }
    
    printf("Good bye.. and I hope you're happy all the time. :D\n");
    sleep(3.5);
    return 0;
}
