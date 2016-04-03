#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <fstream>

#define href "d:\\projects\\clion\\pricelist\\price.txt"

using namespace std;

struct element
{
    double max = 0;
    double min = -1;
    char name[255];
    element* next = NULL;
};

element *pricelist = new element;


element* findInList(element* head, char* value)
{
    while (head->next!=NULL)
    {
        if ((strcmp(head->name,value))==0)
        {
            return head;
        };
        head=head->next;
    };
    if ((strcmp(head->name,value))==0)
    {
        return head;
    };
    return NULL;
}


void addToEnd(element* head, char* name, double price)
{
    while (head -> next != NULL)
    {
        head=head->next;
    };
    element* last_el = new element;
    head->next = last_el;
    strcpy(last_el -> name , name);
    last_el -> max = price;
    last_el -> min = price;
}


void print_list(element* head)
{
    if (head == NULL)
    {
        printf("THE LIST IS EMPTY!");
        exit(42);
    }
    while (head -> next != NULL)
    {
        printf("%s: %.2f-%.2f \n",head->name,head->max,head->min);
        head=head->next;
    };

    printf("%s: %.2f-%.2f \n",head->name,head->max,head->min);
}




void readBase()
{
    FILE* fp = fopen(href,"r");

    char temp[255];

    element* tmp_elt;
    double tmp_price;

    while(!feof(fp))
    {
        fgets(temp, 255, fp);
        char *pch = strtok(temp, " -:_\n");
        while (pch != NULL)                         // ???? ???? ???????
        {
            tmp_elt=findInList(pricelist,pch);
            if (tmp_elt!=NULL)
            {
                tmp_price=atof(strtok(NULL, " -:_\n"));
                if(tmp_elt->max < tmp_price)
                {
                    tmp_elt->max = tmp_price;
                }
                if(tmp_elt->min > tmp_price || tmp_elt->min == -1)
                {
                    tmp_elt->min = tmp_price;
                }
            } else
            {
                tmp_price=atof(strtok(NULL, " -:_\n"));
                addToEnd(pricelist,pch,tmp_price);
            };
            pch = strtok(NULL, " -:_\n");
        }
    }
    fclose(fp);
}

int main() {
    readBase();
    print_list(pricelist->next);
    getchar();
    return 0;
}