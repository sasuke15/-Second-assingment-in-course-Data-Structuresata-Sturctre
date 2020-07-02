

/*
Assigend by:
Shay Bach #204263842,:61108
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {

    int data;
    int pow;
    struct node* next;
    struct node* previuse;

} Node;

/* Declarations of other functions */

/* ------------------------------- */
void Ex1();
void EX2();

/* Function definitions */

/* ------------------- */

/* Exercise1 */
void Push(char x, Node** ps)

{

    Node* temp;

    temp = (Node*)malloc(sizeof(Node));

    temp->data = x;

    temp->next = *ps;

    *ps = temp;
}
void Pop(Node** ps)

{

    Node* temp;

    temp = *ps;

    *ps = temp->next;

    free(temp);
}
void table(char* string)

{

    Node* s1 = NULL;

    Node* s2 = NULL;

    int i = 0, j;

    char curr;

    char result = 'Z';

    int condition = 1;

    printf("Operation	Operand1	Operand2	Result\n");

    while (string[i] == ' ' && string[i] != '\0')
        i++;

    if (string[i] != '\0')
        Push(string[i], &s1);

    i++;

    while (string[i] == ' ' && string[i] != '\0')
        i++;

    while (s1 != NULL)

    {

        if (s2 != NULL)

        {

            while (condition == 1)

            {

                if ((string[i] == '\0') || ((string[i] == '*' || string[i] == '/') && (s2->data != '+' && s2->data != '-')) || (string[i] == '+' || string[i] == '-'))

                {

                    printf("   %c\t", s2->data);

                    Pop(&s2);

                    curr = s1->data;

                    Pop(&s1);

                    printf("           %c\t", s1->data);

                    Pop(&s1);

                    printf("           %c\t", curr);

                    printf("           %c\t", result);

                    printf("\n\n");

                    Push(result, &s1);

                    --result;
                }

                else

                    condition = 0;

                if (s2 == NULL)

                    condition = 0;
            }

            condition = 1;
        }

        if (string[i] == '\0')

            Pop(&s1);

        else

        {

            Push(string[i], &s2);

            j = 1;

            while (string[i + j] == ' ' && string[i + j] != '\0')
                j++;

            Push(string[i + j], &s1);

            j++;

            while (string[i + j] == ' ' && string[i + j] != '\0')
                j++;

            i = i + j;
        }
    }
}
void Ex1()

{

    int n;

    char* string;

    printf("please enter the size of the string\n");

    scanf("%d", &n);

    string = (char*)malloc((n + 1) * sizeof(char));

    printf("please enter the string \n");

    rewind(stdin);
    gets(string);

    printf("\n");

    table(string);
}

/* Exercise2 */
void create_Polynomail(Node** Polynomial)

{

    *Polynomial = NULL;
}
void add_dyget(Node** Polynomial, int num, int pow)

{

    Node *curr, *temp;

    if (*Polynomial == NULL)

    {

        *Polynomial = (Node*)malloc(sizeof(Node));

        (*Polynomial)->data = num;

        (*Polynomial)->pow = pow;

        (*Polynomial)->next = NULL;

        (*Polynomial)->previuse = NULL;
    }

    else

    {

        curr = *Polynomial;

        while (curr != NULL)

        {

            if (curr->pow == pow)

            {

                curr->data += num;

                break;
            }

            if (curr->pow > pow)

            {

                temp = (Node*)malloc(sizeof(Node));

                temp->data = num;

                temp->pow = pow;

                if (curr->previuse == NULL)

                {

                    temp->next = curr;

                    curr->previuse = temp;

                    temp->previuse = NULL;

                    *Polynomial = temp;
                }

                else

                {

                    temp->next = curr;

                    temp->previuse = curr->previuse;

                    temp->previuse->next = temp;

                    curr->previuse = temp;
                }

                break;
            }

            if (curr->next == NULL)

            {

                temp = (Node*)malloc(sizeof(Node));

                temp->data = num;

                temp->pow = pow;

                curr->next = temp;

                temp->previuse = curr;

                temp->next = NULL;

                break;
            }

            curr = curr->next;
        }
    }
}
void null(Node** Polynomail)

{

    Node* curr;

    while (*Polynomail != NULL)

    {

        curr = *Polynomail;

        *Polynomail = (*Polynomail)->next;

        free(curr);
    }
}
void pluse(Node* Polynomial_1, Node* Polynomial_2, Node** result)

{

    Node *curr, *temp, *whil;

    Node *A = Polynomial_1, *B = Polynomial_2;

    while (Polynomial_1 != NULL)

    {

        add_dyget(result, Polynomial_1->data, Polynomial_1->pow);

        Polynomial_1 = Polynomial_1->next;
    }

    while (Polynomial_2 != NULL)

    {

        add_dyget(result, Polynomial_2->data, Polynomial_2->pow);

        Polynomial_2 = Polynomial_2->next;
    }

    curr = *result;

    while (curr != NULL)

    {

        if (curr->data == 0)

        {

            temp = curr;

            if (curr->previuse == NULL && curr->next != NULL)

            {

                curr = curr->next;

                *result = curr;

                curr->previuse = NULL;
            }

            else

                if (curr->next == NULL && curr->previuse != NULL)

            {

                curr->previuse->next = NULL;

                curr = curr->next;
            }

            else

                if (curr->next != NULL && curr->previuse != NULL)

            {

                whil = curr->previuse;

                curr = curr->next;

                whil->next = curr;

                curr->previuse = whil;
            }

            else

                if (curr->next == NULL && curr->previuse == NULL)

            {

                curr = curr->next;

                *result = curr;
            }

            free(temp);
        }

        else

            if (curr != NULL)

            curr = curr->next;
    }

    if (A != NULL)

        null(&A);

    if (B != NULL)

        null(&B);
}
void minuse(Node* Polynomial_1, Node* Polynomial_2, Node** result)

{

    Node *curr, *temp, *whil;

    Node *A = Polynomial_1, *B = Polynomial_2;

    while (Polynomial_1 != NULL)

    {

        add_dyget(result, Polynomial_1->data, Polynomial_1->pow);

        Polynomial_1 = Polynomial_1->next;
    }

    while (Polynomial_2 != NULL)

    {

        add_dyget(result, -1 * (Polynomial_2->data), Polynomial_2->pow);

        Polynomial_2 = Polynomial_2->next;
    }

    curr = *result;

    while (curr != NULL)

    {

        if (curr->data == 0)

        {

            temp = curr;

            if (curr->previuse == NULL && curr->next != NULL)

            {

                curr = curr->next;

                *result = curr;

                curr->previuse = NULL;
            }

            else

                if (curr->next == NULL && curr->previuse != NULL)

            {

                curr->previuse->next = NULL;

                curr = curr->next;
            }

            else

                if (curr->next != NULL && curr->previuse != NULL)

            {

                whil = curr->previuse;

                curr = curr->next;

                whil->next = curr;

                curr->previuse = whil;
            }

            else

                if (curr->next == NULL && curr->previuse == NULL)

            {

                curr = curr->next;

                *result = curr;
            }

            free(temp);
        }

        else

            if (curr != NULL)

            curr = curr->next;
    }

    if (A != NULL)

        null(&A);

    if (B != NULL)

        null(&B);
}
void time_number(Node** Polynomail, int num)

{

    Node* curr;

    if (num == 0)

        null(Polynomail);

    curr = *Polynomail;

    while (curr != NULL)

    {

        curr->data *= num;

        curr = curr->next;
    }
}
int size(Node* curr)

{

    if (curr == NULL)

        return -1;

    while (curr->next != NULL)

        curr = curr->next;

    return curr->pow;
}
int print(Node* curr)

{

    if (curr == NULL)

    {

        printf("0\n\n");

        return -1;
    }

    while ((curr)->next != NULL)

        curr = curr->next;

    while (curr != NULL)

    {

        if (curr->data > 0 && curr->next != NULL)

            printf("+");

        if (curr->pow == 0)

            printf("%d", curr->data);

        else

        {

            if (curr->data == 1 || curr->data == -1)

            {

                if (curr->data == -1)

                    printf("-");

                if (curr->pow == 1)

                    printf("x");

                else

                    printf("x^%d", curr->pow);
            }

            else

            {

                if (curr->pow == 1)

                    printf("%dx", curr->data);

                else

                    printf("%dx^%d", curr->data, curr->pow);
            }
        }

        curr = curr->previuse;
    }

    printf("\n\n");
}
void bonous(Node* Polynomial_1, Node* Polynomial_2, Node** result)

{

    Node *curr, *temp, *whil;

    Node *A = Polynomial_1, *B = Polynomial_2;

    while (Polynomial_1 != NULL)

    {

        Polynomial_2 = B;

        while (Polynomial_2 != NULL)

        {

            add_dyget(result, (Polynomial_1->data) * (Polynomial_2->data), (Polynomial_1->pow) + (Polynomial_2->pow));

            Polynomial_2 = Polynomial_2->next;
        }

        Polynomial_1 = Polynomial_1->next;
    }

    curr = *result;

    while (curr != NULL)

    {

        if (curr->data == 0)

        {

            temp = curr;

            if (curr->previuse == NULL && curr->next != NULL)

            {

                curr = curr->next;

                *result = curr;

                curr->previuse = NULL;
            }

            else

                if (curr->next == NULL && curr->previuse != NULL)

            {

                curr->previuse->next = NULL;

                curr = curr->next;
            }

            else

                if (curr->next != NULL && curr->previuse != NULL)

            {

                whil = curr->previuse;

                curr = curr->next;

                whil->next = curr;

                curr->previuse = whil;
            }

            else

                if (curr->next == NULL && curr->previuse == NULL)

            {

                curr = curr->next;

                *result = curr;
            }

            free(temp);
        }

        else

            if (curr != NULL)

            curr = curr->next;
    }

    if (A != NULL)

        null(&A);

    if (B != NULL)

        null(&B);
}
void EX2()

{

    Node* Polynomial_1;

    Node* Polynomial_2;

    Node* result;

    int condition = 8;

    int num, pow;

    create_Polynomail(&Polynomial_1);

    create_Polynomail(&Polynomial_2);

    create_Polynomail(&result);

    while (condition != 0)

    {

        printf("To add dyget to the polynomial enter:1\nTo add a polynomial to the current polynomial enter:2\nTo subtract a polynomial from the current polynomial enter:3\nTo time a number to the current polynomial enter:4\nTo see the size of the polynomial enter:5\nTo clear the polynomial enter:6\nTo time the current  polynomail with another polynomail enter:7\nTo exit enter 0\n\n");

        scanf("%d", &condition);

        if (condition == 1)

        {

            printf("please enter the dygets here ( to end the dygets entrance ender num = 0 )\n\n num here ->  x^  <- pow here\n");

            scanf("%d%d", &num, &pow);

            while (num != 0)

            {

                add_dyget(&Polynomial_1, num, pow);

                printf("num here ->  x^  <- pow here\n");

                scanf("%d%d", &num, &pow);
            }

            printf("\nthe new polynomail is:");

            print(Polynomial_1);
        }

        if (condition == 2)

        {

            printf("please enter the dygets here ( to end the dygets entrance ender num = 0 )\n\n num here ->  x^  <- pow here\n");

            scanf("%d%d", &num, &pow);

            while (num != 0)

            {

                add_dyget(&Polynomial_2, num, pow);

                printf("num here ->  x^  <- pow here\n");

                scanf("%d%d", &num, &pow);
            }

            printf("\nthe  polynomail is:");

            print(Polynomial_2);

            pluse(Polynomial_1, Polynomial_2, &result);

            Polynomial_1 = result;

            create_Polynomail(&result);

            create_Polynomail(&Polynomial_2);

            printf("\nthe current result is:");

            print(Polynomial_1);
        }

        if (condition == 3)

        {

            printf("please enter the dygets here ( to end the dygets entrance ender num = 0 )\n\n num here ->  x^  <- pow here\n");

            scanf("%d%d", &num, &pow);

            while (num != 0)

            {

                add_dyget(&Polynomial_2, num, pow);

                printf("num here ->  x^  <- pow here\n");

                scanf("%d%d", &num, &pow);
            }

            printf("\nthe  polynomail is:");

            print(Polynomial_2);

            minuse(Polynomial_1, Polynomial_2, &result);

            Polynomial_1 = result;

            create_Polynomail(&Polynomial_2);

            create_Polynomail(&result);

            printf("\nthe current result is:");

            print(Polynomial_1);
        }

        if (condition == 4)

        {

            printf("Please enter the number\n");

            scanf("%d", &num);

            time_number(&Polynomial_1, num);

            printf("\nthe result is:");

            print(Polynomial_1);
        }

        if (condition == 5)

        {

            if (size(Polynomial_1) != -1)

                printf("the size of polynomial is:%d\n\n", size(Polynomial_1));

            else

                printf(" Zero (Empty Polynomial)\n ");
        }

        if (condition == 6)

        {

            null(&Polynomial_1);

            printf("\nthe new polynomail is:");

            print(Polynomial_1);
        }

        if (condition == 7)

        {

            printf("please enter the dygets here ( to end the dygets entrance ender num = 0 )\n\n num here ->  x^  <- pow here\n");

            scanf("%d%d", &num, &pow);

            while (num != 0)

            {

                add_dyget(&Polynomial_2, num, pow);

                printf("num here ->  x^  <- pow here\n");

                scanf("%d%d", &num, &pow);
            }

            printf("\nthe polynomial is:");

            print(Polynomial_2);

            bonous(Polynomial_1, Polynomial_2, &result);

            Polynomial_1 = result;

            create_Polynomail(&result);

            create_Polynomail(&Polynomial_2);

            printf("\nthe current result is:");

            print(Polynomial_1);
        }

        if (condition == 0)

            null(&Polynomial_1);
    }
}

int main()
{
    int select = 0, i, all_Ex_in_loop = 0;
    printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
    if (scanf("%d", &all_Ex_in_loop) == 1)
        do {
            for (i = 1; i <= 2; i++)
                printf("Ex%d--->%d\n", i, i);
            printf("EXIT-->0\n");
            do {
                select = 0;
                printf("please select 0-2 : ");
                scanf("%d", &select);
            } while ((select < 0) || (select > 2));
            switch (select) {
            case 1:
                Ex1();
                break;
            case 2:
                EX2();
                break;
            }
        } while (all_Ex_in_loop && select);
    return 0;
}


