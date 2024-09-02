#define stackinitsize 1000
#define stackaddsize 100

#include <iostream>
using namespace std;

typedef struct
{
    int* top;
    int* base;
    int stacksize;
}stack;

int initstack(stack& s)
{
    s.base = (int*)malloc(stackinitsize * sizeof(int));
    if (!s.base)
        return -1;
    s.top = s.base;
    s.stacksize = stackinitsize;
    return 0;
}

int push(stack& s, int c)
{
    if (s.top - s.base >= s.stacksize)
    {
        s.base = (int*)realloc(s.base,(s.stacksize + stackaddsize) * sizeof(int));
        if (!s.base)
            return -1;
        s.top = s.base + s.stacksize;
        s.stacksize += stackaddsize;
    }
    *s.top++ = c;
    return 0;
}

int pop(stack& s)
{
    if (s.top == s.base)
        return -1;
    --s.top;
    return 0;
}

int clearstack(stack& s)
{
    s.top = s.base;
    return 0;
}

int main()
{
    stack s;
    initstack(s);
    char c;
    c = getchar();
    int position = -1, p1 = -1, p = -1, n = 0, num = 0;
    if (c == '"')
    {
        c = getchar();
        if (c == '"')
            ++p;
        while (c != '"')
        {
            switch (c)
            {
                case '(':
                    ++position;
                    push(s, position);
                    break;
                case ')':
                    ++position;
                    if (s.top == s.base)
                    {
                        clearstack(s);
                        n = position - p1 - 1;
                        p1 = position;
                        if (num < n)
                        {
                            num = n;
                            p = position - n;
                        }
                    }
                    else
                        pop(s);
                    break;
            }
            c = getchar();
        }
        if (s.top == s.base && position != p1)
        {
            n = position - p1;
            if (num < n)
            {
                num = n;
                p = position - n + 1;
            }
        }
         if (s.top != s.base)
        {
            n = *s.base - p1 - 1;
            if (num < n)
            {
                num = n;
                p = p1 + 1;
            }
            for (int i = 1; i < s.top - s.base; ++i)
            {
                n = *(s.base + i) - *(s.base + i - 1) - 1;
                if (num < n)
                {
                    num = n;
                    p = *(s.base + i - 1) + 1;
                }
            }
            n = position - *(s.top - 1);
            if (num < n)
            {
                num = n;
                p = *(s.top - 1) + 1;
            }
        }
    }
    cout << num << " " << p << endl;
    return 0;
}
