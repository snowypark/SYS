#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    struct student *next;
};


int main(int argc, char* argv[])
{

    int count = 0, id;
    char name[20];
    struct student *p;
	struct student *head = NULL; 
	struct student *ttt = NULL;
    struct student *tmp;

    printf("학번과  이름을 입력하세요\n");

    while (scanf("%d %s", &id, name) == 2)  {
        p = (struct student *) malloc(sizeof(struct student));;
        if (p == NULL) {
            perror("malloc");
            exit(1);
        }
        p->id = id;
        strcpy(p->name,name);
        
        if(head==NULL){
            head=p;
            ttt=p;
            
        }
        else {
            ttt->next = p;
            ttt = p;
        }

       
    }

    printf("\n* 학생 정보 *\n");
    tmp = head;
    while (tmp != ttt)  {
        
        printf("학번: %d 이름: %s\n", tmp->id,  tmp->name);
        tmp = tmp->next;
    }

    printf("학번: %d 이름 : %s\n", tmp->id, tmp->name);
    return 0;
}
