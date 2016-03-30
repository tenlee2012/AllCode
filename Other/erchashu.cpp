/******************************************************************************************* 
习题：实现二叉树的生成、先序遍历、中序遍历、后序遍历，统计二叉树的叶子结点、非叶子结点 
 
程序中已给出二叉树生成函数CreateBiTree、先序遍历函数PreOrderTraverse和统计二叉树的叶子结点函数NonLeafCount 
 
 基本要求(必做)： 
1、将中序遍历(InOrderTraverse)、后序遍历(PostOrderTraverse)函数补充完整 
2、将统计二叉树的非叶子结点函数NonLeafCount补充完整 
3、程序中存在一个显著错误，请找出后改正之 
 
 
选作：在程序中实现以下功能 
1、求二叉树的根结点Root(T) 
2、求某结点的父结点Parent(T,e) 
3、求结点的左孩子LeftChild(T,e) 
4、求结点的右孩子RightChild(T,e) 
5、求结点的左兄弟LeftSibling(T,e) 
6、求结点的右兄弟RightSibling(T,e) 
7、插入孩子结点InsertChild(T,p,LR,c) 
8、删除孩子结点DeleteChild(T,p,LR) 
 
 
注意: 
1、程序运行时，设初始输入序列为"ABC  DE G  F    " 
2、本作业成绩按最后完成的功能多少评分 
******************************************************************************************/  
  
  
#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h>  
#include <stack>  
#include <stdlib.h>  
using namespace std;  
int leaf_num;//叶子结点数目  
int non_leaf_num;  
  
typedef char TElemType;  //定义树中结点的数据域的类型为字符型  
typedef struct BiTNode //树的存储结构的定义  
{  
    TElemType data; //结点的数据域  
    struct BiTNode * lchild, *rchild; //结点的左右孩子指针  
} BiTNode, *BiTree;  
  
void CreateBiTree(BiTree & T)//按先序序列创建二叉树 "ABC  DE G  F    "  
{  
    TElemType ch;  
    scanf("%c", &ch);  
  
    while (ch == '\n')  
    {  
        scanf("%c", &ch);    //吃掉一些讨厌的回车  
    }  
  
    if (ch == ' ')  
    {  
        T = NULL;  
    }  
    else  
    {  
        T = (BiTNode *)malloc(sizeof(BiTNode));  
        T->data = ch;  
        CreateBiTree(T->lchild);  
        CreateBiTree(T->rchild);  
    }  
}  
  
void PreOrderTraverse(BiTree T)  //先序遍历  
{  
    if (T)  
    {  
        printf("%c", T->data); //访问根结点  
        PreOrderTraverse(T->lchild);  //先序访问左子树  
        PreOrderTraverse(T->rchild);  //先序访问右子树  
    }  
}  
  
void InOrderTraverse(BiTree T)//中序递归遍历  
{  
    if (T)  
    {  
        InOrderTraverse(T->lchild);  //中序访问左子树  
        printf("%c", T->data);  
        InOrderTraverse(T->rchild);  //中序访问右子树  
    }  
}  
void InOrderTraverse_2(BiTree T)//中序非递归遍历  
{  
    stack<BiTree> S;  
    BiTree p;  
    S.push(T);  
  
    while (!S.empty())  
    {  
        p = S.top();  
  
        while (p)  
        {  
            S.push(p->lchild);  
            p = p->lchild;  
        }  
  
        S.pop();  
  
        if (!S.empty())  
        {  
            p = S.top();  
            S.pop();  
  
            if (p->data == ' ')  
            {  
                return;  
            }  
  
            printf("%c", p->data);  
            S.push(p->rchild);  
        }  
    }  
}  
  
void PostOrderTraverse(BiTree T) //后序遍历  
{  
    if (T)  
    {  
        PostOrderTraverse(T->lchild);  //后序访问左子树  
        PostOrderTraverse(T->rchild);  //后序访问右子树  
        printf("%c", T->data);  
    }  
}  
  
void LeafCount(BiTree T)//统计二叉树叶子结点数目  
{  
    if (T)  
    {  
        if (T->lchild == NULL && T->rchild == NULL) //判断条件：当前结点无左右孩子则该结点为叶子结点  
        {  
            leaf_num++;    //计算器加1  
        }  
  
        LeafCount(T->lchild);//若非叶子结点则分别统计其左、右子树  
        LeafCount(T->rchild);  
    }  
}  
  
void NonLeafCount(BiTree T)//统计二叉树非叶子结点数目  
{  
    if (T)  
    {  
        if (T->lchild != NULL || T->rchild != NULL) //判断条件：当前结点有右孩子则该结点为非叶子结点  
        {  
            non_leaf_num++;    //计算器加1  
        }  
  
        NonLeafCount(T->lchild);//若非叶子结点则分别统计其左、右子树  
        NonLeafCount(T->rchild);  
    }  
}  
void Find(char f, char e, BiTree T) //找得到了父结点就找到了一切  
{  
    if (!T)  
    {  
        printf("树为空，请先建树!\n");  
        return;  
    }  
  
    BiTree par, now;  
    int flag = 0; // 1 左, 2 右;  
  
    if (T->data == e)  
    {  
        if (f == 'b')  
        {  
            printf("%c 没有父结点\n", e);  
        }  
        else if (f == 'c')  
        {  
            if (T->lchild)  
            {  
                printf("左孩子是 %c\n", T->lchild->data);  
            }  
            else  
            {  
                printf("%c 没有左孩子结点\n", e);  
            }  
        }  
        else if (f == 'd')  
        {  
            if (T->rchild)  
            {  
                printf("右孩子是 %c\n", T->rchild->data);  
            }  
            else  
            {  
                printf("%c 没有右孩子结点\n", e);  
            }  
        }  
        else if (f == 'e')  
        {  
            printf("%c 没有左兄弟\n", e);  
        }  
        else  
        {  
            printf("%c 没有右兄弟\n", e);  
        }  
        return;  
    }  
  
    stack<BiTree> S;  
  
    while (T || !S.empty()) //先序非递归遍历  
    {  
        while (T)  
        {  
            S.push(T);  
  
            if (T->lchild) //先判断该结点是否有左孩子结点  
                if (T->lchild->data == e) //再判断左孩子结点是否和e相等  
                {  
                    flag = 1;  
                    par = T;  
                    now = T->lchild;  
                    break;  
                }  
  
            if (T->rchild) //先判断该结点是否有右孩子结点  
                if (T->rchild->data == e) //再判断右孩子结点是否和e相等  
                {  
                    flag = 2;  
                    par = T;  
                    now = T->rchild;  
                    break;  
                }  
  
            T = T->lchild;  
        }  
  
        if (flag != 0)  
        {  
            break;  
        }  
  
        T = S.top();  
        S.pop();  
        T = T->rchild;  
    }  
  
    if (!flag)  
    {  
        printf("没有这个结点\n");  
        return;  
    }  
  
    if (f == 'b')  
    {  
        printf("%c 的父结点是%c\n", e, par->data);  
    }  
    else if (f == 'c')  
    {  
        if (!now->lchild)  
        {  
            printf("%c 没有左孩子结点\n", e);  
        }  
        else  
        {  
            printf("%c 左孩子是 %c\n", e, now->lchild->data);  
        }  
    }  
    else if (f == 'd')  
    {  
        if (!now->rchild)  
        {  
            printf("%c 没有右孩子结点\n", e);  
        }  
        else  
        {  
            printf("%c 右孩子是 %c\n", e, now->rchild->data);  
        }  
    }  
    else if (f == 'e')  
    {  
        if (flag == 1 || !par->lchild)  
        {  
            printf("%c 没有左兄弟结点\n", e);  
        }  
        else  
        {  
            printf("%c 的左兄弟结点是 %c\n", e, par->lchild->data);  
        }  
    }  
    else  
    {  
        if (flag == 2 || !par->rchild)  
        {  
            printf("%c 没有右兄弟结点\n", e);  
        }  
        else  
        {  
            printf("%c 的右兄弟结点是 %c\n", e, par->rchild->data);  
        }  
    }  
}  
  
void Insert(BiTree & TT) //插入树  
{  
    int LR;  
    char p,  flag;  
    BiTree now, next, C, f, T = TT;  
    stack<BiTree> S;  
    printf("请先建立要插入的树\n");  
    CreateBiTree(C);  
    f = C;  
    printf("请输入p(结点),LR(左孩子右孩子0,1):\t");  
    scanf(" %c%d", &p, &LR);  
  
    while (T || !S.empty()) //先序非递归遍历  
    {  
        while (T)  
        {  
            S.push(T);  
  
            if (T->data == p) //再判断左孩子结点是否和e相等  
            {  
                flag = 1;  
                now = T;  
                break;  
            }  
  
            T = T->lchild;  
        }  
  
        if (flag != 0)  
        {  
            break;  
        }  
  
        T = S.top();  
        S.pop();  
        T = T->rchild;  
    }  
  
    if (!flag || LR > 1)  
    {  
        printf("没有结点 %c 或 LR输入错误\n", p);  
        return;  
    }  
  
    if (LR == 0)  
    {  
        next = now->lchild;  
        now->lchild = C;  
    }  
    else  
    {  
        next = now->rchild;  
        now->rchild = C;  
    }  
  
    while (f->rchild) //p所指结点的原有左子树或右子树成为c的右子树  
    {  
        f = f->rchild;  
    }  
  
    f->rchild = next;  
}  
void destroyBiTree(BiTree & T) //删除树  
{  
    if (T)  
    {  
        destroyBiTree(T->lchild);  
        destroyBiTree(T->rchild);  
        free(T);  
        T = NULL;  
    }  
}  
void DelChild(BiTree & TT, char p, int LR)  
{  
    BiTree now, T = TT;  
    int flag = 0;  
    stack <BiTree> S;  
  
    while (T || !S.empty()) //先序非递归遍历  
    {  
        while (T)  
        {  
            S.push(T);  
  
            if (T->data == p) //再判断左孩子结点是否和e相等  
            {  
                flag = 1;  
                now = T;  
                break;  
            }  
  
            T = T->lchild;  
        }  
  
        if (flag != 0)  
        {  
            break;  
        }  
  
        T = S.top();  
        S.pop();  
        T = T->rchild;  
    }  
  
    if (!flag || LR > 1)  
    {  
        printf("没有结点 %c 或 LR输入错误\n", p);  
        return;  
    }  
  
    if (LR == 0)  
    {  
        destroyBiTree(now->lchild);  
    }  
    else  
    {  
        destroyBiTree(now->rchild);  
    }  
}  
int main()  
{  
    //freopen("1.txt", "r", stdin);  
    BiTree bt;  
    int flag = 1, LR; //用于switch语句的控制位  
    char option, e, c;//用户输入字符  
  
    /** 按先序输入二叉树序列，构造二叉树**/  
    printf("构造二叉树，请按先序输入二叉树序列\n");  
    CreateBiTree(bt);  
  
    while (flag)  
    {  
        printf("\n请选择：\n");  
        printf("1. 构造新二叉树\n");  
        printf("2. 二叉树先序遍历\n");  
        printf("3. 二叉树中序遍历\n");  
        printf("4. 二叉树后序遍历\n");  
        printf("5. 统计二叉树叶子结点数目\n");  
        printf("6. 统计二叉树非叶子结点数目\n");  
        printf("a、求二叉树的根结点\n");  
        printf("b、求某结点的父结点Parent(T,e)\n");  
        printf("c、求结点的左孩子LeftChild(T,e)\n");  
        printf("d、求结点的右孩子RightChild(T,e)\n");  
        printf("e、求结点的左兄弟LeftSibling(T,e)\n");  
        printf("f、求结点的右兄弟RightSibling(T,e)\n");  
        printf("g、插入孩子结点InsertChild(T,p,LR,c)\n");  
        printf("h、删除孩子结点DeleteChild(T,p,LR)\n");  
        printf("7. 退出程序\n");  
  
        scanf(" %c", &option);  
        system("clear");  
  
        switch (option)  
        {  
            case '1':  
                printf("请输入二叉树序列:\n");  
                CreateBiTree(bt);  
                break;  
  
            case '2':  
                printf("二叉树先序遍历结果:  ");  
                PreOrderTraverse(bt);  
                printf("\n");  
                break;  
  
            case '3':  
                printf("二叉树中序递归遍历结果:   ");  
                InOrderTraverse(bt);  
                printf("    中序非递归遍历结果:   ");  
                InOrderTraverse_2(bt);  
                printf("\n");  
                break;  
  
            case '4':  
                printf("二叉树后序遍历结果:   ");  
                PostOrderTraverse(bt);  
                printf("\n");  
                break;  
  
            case '5':  
                leaf_num = 0;  
                LeafCount(bt);  
                printf("二叉树叶子结点数目:   %d\n", leaf_num);  
                break;  
  
            case '6':  
                non_leaf_num = 0;  
                NonLeafCount(bt);  
                printf("二叉树叶非子结点数目:   %d\n", non_leaf_num);  
                break;  
  
            case 'a':  
                printf("二叉树的根节点是:\t%c\n", bt->data);  
                break;  
  
            case 'b':  
                printf("请输入该点(求父结点):\t");  
                scanf(" %c", &e);  
                Find(option, e, bt);  
                break;  
  
            case 'c':  
                printf("请输入该点(求左孩子):\t");  
                scanf(" %c", &e);  
                Find(option, e, bt);  
                break;  
  
            case 'd':  
                printf("请输入该点(求右孩子):\t");  
                scanf(" %c", &e);  
                Find(option, e, bt);  
                break;  
  
            case 'e':  
                printf("请输入该点(求左兄弟):\t");  
                scanf(" %c", &e);  
                Find(option, e, bt);  
                break;  
  
            case 'f':  
                printf("请输入该点(求右兄弟):\t");  
                scanf(" %c", &e);  
                Find(option, e, bt);  
                break;  
  
            case 'g':  
                Insert(bt);  
                break;  
  
            case 'h':  
                printf("请输入要删除的结点p的LR(0,1): ");  
                scanf(" %c %d", &c, &LR);  
                DelChild(bt, c, LR);  
                break;  
  
            case '7':  
                flag = 0;  
                printf("程序结束，按任意键退出！\n");  
                break;  
  
            default:  
                {  
                    printf("输入错误，重新输入\n");  
                    break;  
                }  
  
                //  
        }// end switch  
  
        //option = getchar();  
    }//end while  
  
    return 0;  
}//end  

