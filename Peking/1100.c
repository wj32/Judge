#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

#define OP_LIT 0
#define OP_ADD 1
#define OP_SUB 2
#define OP_MUL 3
#define OP_UNK 4

typedef struct _node
{
    int op;
    union
    {
        int data;
        struct
        {
            struct _node *left;
            struct _node *right;
        } s;
    } u;
} node;

node *parse(char **s);

int eat(char **p)
{
    char *s = *p;
    int n = 0;
    
    while (isdigit(*s))
    {
        n = (n * 10) + *s - '0';
        s++;
    }
    
    *p = s;
    
    return n;
}

void eatspace(char **p)
{
    while (**p == ' ' || **p == '\n')
        (*p)++;
}

node nodes[100];
int currentnode;
int *unkops[100];
int unkopscount;

node *makenode(void)
{
    return &nodes[currentnode++];
}

node *parseint(char **s)
{
    node *d;
    
    eatspace(s);
    d = makenode();
    d->op = OP_LIT;
    d->u.data = eat(s);
    
    return d;
}

node *parsegroup(char **s)
{
    if (**s == '(')
    {
        node *d;
        
        (*s)++;
        d = parse(s);
        eatspace(s);
        assert(**s == ')');
        (*s)++;
        
        return d;
    }
    else if (isdigit(**s))
    {
        return parseint(s);
    }
    else
    {
        assert(0);
    }
}

node *parse(char **s)
{
    node *left = 0;
    node *right;
    
    while (1)
    {
        eatspace(s);
        
        if (**s == ')' || **s == 0)
            break;
        
        right = parsegroup(s);
        eatspace(s);
        
        if (left)
        {
            node *oldleft = left;
            
            left = makenode();
            left->op = OP_UNK;
            left->u.s.left = oldleft;
            left->u.s.right = right;
            unkops[unkopscount++] = &left->op;
        }
        else
        {
            left = right;
        }
    }
    
    return left;
}

int eval(node *d)
{
    switch (d->op)
    {
    case OP_LIT:
        return d->u.data;
    case OP_ADD:
        return eval(d->u.s.left) + eval(d->u.s.right);
    case OP_SUB:
        return eval(d->u.s.left) - eval(d->u.s.right);
    case OP_MUL:
        return eval(d->u.s.left) * eval(d->u.s.right);
    default:
        assert(0);
    }
}

int docase(int left, node *d)
{
    int i;
    
    // init all to +
    for (i = 0; i < unkopscount; i++)
        *unkops[i] = OP_ADD;
    
    while (1)
    {
        int carry = 1;
        
        if (eval(d) == left)
            return 1;
        
        for (i = 0; i < unkopscount; i++)
        {
            if (!carry)
                break;
            
            (*unkops[i])++;
            carry = 0;
            
            if (*unkops[i] > OP_MUL)
            {
                *unkops[i] = OP_ADD;
                carry = 1;
            }
        }
        
        if (carry)
            break;
    }
    
    return 0;
}

void printnode(node *d)
{
    char c;
    
    switch (d->op)
    {
    case OP_LIT:
        printf("%d", d->u.data);
        break;
    case OP_ADD:
    case OP_SUB:
    case OP_MUL:
        printnode(d->u.s.left);
        
        switch (d->op)
        {
        case OP_ADD:
            c = '+';
            break;
        case OP_SUB:
            c = '-';
            break;
        case OP_MUL:
            c = '*';
            break;
        default:
            assert(0);
        }
        
        printf("%c", c);
        
        if (d->u.s.right->op != OP_LIT)
            printf("(");
        
        printnode(d->u.s.right);
        
        if (d->u.s.right->op != OP_LIT)
            printf(")");
        
        break;
    default:
        assert(0);
    }
}

int main(int argc, char *argv[])
{
    char str[81];
    int eqn = 0;
    
    while (1)
    {
        node *d;
        char *p;
        int left;
        
        fgets(str, sizeof(str), stdin);
        
        if (str[0] == '0' && str[1] == '\n')
            break;
        
        eqn++;
        currentnode = 0;
        unkopscount = 0;
        
        p = str;
        left = eat(&p);
        eatspace(&p);
        // equals sign
        assert(*p == '=');
        p++;
        eatspace(&p);
        
        d = parse(&p);
        
        printf("Equation #%d:\n", eqn);
        
        if (docase(left, d))
        {
            printf("%d=", left);
            printnode(d);
            printf("\n");
        }
        else
        {
            printf("Impossible\n");
        }
        
        printf("\n");
    }
    
    return 0;
}
