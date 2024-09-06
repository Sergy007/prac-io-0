#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListItem
{
    char *str;
    struct ListItem *next;
};

struct ListItem *list_dup(const struct ListItem *list)
{
    struct ListItem *begin = NULL;
    struct ListItem *tmp;
    int flag = 1;
    while (list != NULL)
    {
        for (int i = 0; i < strlen(list->str); i++) {
            if (list->str[i] < 'a' || list->str[i] > 'z') {
                flag = 0;
		break;
            }
        }
	if (flag) {
            tmp = (struct ListItem*)malloc(sizeof(struct ListItem));
            tmp->str = (char*)malloc(strlen(list->str) + 1);
            strcpy(tmp->str, list->str);
	    tmp->next = begin;
	    begin = tmp;
        }
	flag = 1;
	list = list->next;
    }
    return begin;
}

struct ListItem *creat()
{
    struct ListItem *tmp;
    struct ListItem *begin = NULL;
    char buf[80];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        tmp = (struct ListItem*) malloc(sizeof(struct ListItem));
        scanf("%s", buf);
        tmp->str = (char*)malloc(strlen(buf) + 1);
        strcpy(tmp->str, buf);
        tmp->next = begin;
        begin = tmp;
    }
    return begin;
}

void print(struct ListItem *l)
{
    while(l) {
        printf("%s ", l->str);
	l = l->next;
    }
    printf("\n");
}

int
main(int argc, char *argv[])
{
    struct ListItem *list = creat();
    print(list);
    struct ListItem *new = list_dup(list);
    print(new);
    return 0;
}
