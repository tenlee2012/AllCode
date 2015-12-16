// what are you talk about
#include "cstdio"
#include "cstring"
#include "cstdlib"
using namespace std;
typedef struct TREE
{
    int th;
    TREE * next[26];
    TREE()
    {
        th = 0;
        memset(next, 0, sizeof(next));
    }
} tree;
TREE *root;
char s[500010][15];

void creat(char * s, int n);
int find(char * s);
void del(TREE *rot);

int main()
{
    //freopen("1.in", "r", stdin);
    root = new TREE();
    char str[3005] = "\0" ;
    char ss[3005], st[6] = "START", en[4] = "END";
    int k = 1, j = 0;

    while (gets(ss))
    {
        if (!strcmp(ss, st))
        {
            continue;
        }

        if (!strcmp(ss, en))
        {
            break;
        }

        for (int i = 0; ss[i]; i++)
        {
            if (ss[i] == ' ')
            {
                strncpy(s[k], ss, i);
                s[k][i] = '\0';
                strcpy(str, &ss[i + 1]);
            }
        }    //printf("%s %s\n", s[k], str);
        creat(str, k);
        k++;
    }

    while (gets(ss))
    {
        if (!strcmp(ss, st))
        {
            continue;
        }

        if (!strcmp(ss, en))
        {
            break;
        }

        for (int i = 0; ss[i]; i++)
        {
            if (ss[i] < 'a' || ss[i] > 'z')
            {
                j = 0;        //printf("%s", str);

                if (find(str))
                {
                    printf("%s", s[find(str)]);
                }
                else
                {
                    printf("%s", str);
                }

                printf("%c", ss[i]);
                memset(str, 0, sizeof(str));
                continue;
            }

            str[j++] = ss[i];
        }        //printf("%s\n", str);

        if (find(str))
        {
            printf("%s\n", str);
        }
        else
        {
            printf("%s\n", str);
        }
    }
    del(root);
    return 0;
}
void creat(char * s, int n)
{
    int len = strlen(s);
    TREE * x = root;

    for (int i = 0; i < len; i++)
    {
        int id = s[i] - 'a';

        if (x->next[id] == NULL)
        {
            x->next[id] = new TREE();
        }

        x = x->next[id];
    }

    x->th = n;
    return;
}

int find(char * s)
{
    TREE * x = root;
    int num;

    for (int i = 0; s[i] != '\0'; i++)
    {
        num = s[i] - 'a';

        if (x->next[num] == NULL)
        {
            return 0;
        }

        x = x->next[num];
    }

    if (x->th)
    {
        return x->th;
    }

    return 0;
}

void del(TREE *rot)
{
    for(int i=0;i<26;i++)
        if(rot->next[i]!=NULL)
            del(rot->next[i]);
    delete rot;
}
