/* 2152118 史君宝 计科 */

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：tj_strlen
  功    能：求字符串str的长度
  输入参数：str[]
  返 回 值：int 型值 字符串str的长度
  说    明：
***************************************************************************/
int tj_strlen(const char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return 0;
    const char *p=str;
    while (*p!= '\0')
        ++p;
    return p-str; //return值可根据需要修改
}

/***************************************************************************
  函数名称：tj_strcat
  功    能：将字符串s2追加到s1的后面
  输入参数：指向s1和s2的指针
  返 回 值：新的s1的指针
  说    明：
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s2 == NULL)
        return s1;
    if (s1 == NULL)
        return s1;
    int s1len;
    s1len = tj_strlen(s1);
    char *p1=s1+s1len;
    const char *p2=s2;
    while (*p2 != '\0')
    {
        *p1 = *p2;
        ++p1;
        ++p2;
    }
    *p1 = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncat(char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s2 == NULL)
        return s1;
    if (s1 == NULL)
        return s1;
    int s1len, s2len;
    s1len = tj_strlen(s1);
    s2len = tj_strlen(s2);
    if (len >= s2len)
        tj_strcat(s1, s2);
    else
    {
        char* p1 = s1 + s1len;
        const char* p2 = s2;
        for (int i = 0; i < len; ++i)
        {
            *p1 = *p2;
            ++p1;
            ++p2;
        }
        *p1 = '\0';
    }
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL)
        return s1;
    if (s2 == NULL)
    {
        *s1 = '\0';
        return s1;
    }
    char* p1 = s1;
    const char* p2 = s2;
    while (*p2 != '\0')
    {
        *p1 = *p2;
        ++p1;
        ++p2;
    }
    *p1 = '\0';
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    if (s2 == NULL)
        return s1;
    if (s1 == NULL)
        return s1;
    char* p1 = s1;
    const char* p2 = s2;
    int s2len;
    s2len = tj_strlen(s2);
    if (len >= s2len)
    {
        for (int i = 0; i < s2len; ++i)
        {
            *p1 = *p2;
            ++p1;
            ++p2;
        }
    }
    else
    {
        for (int i = 0; i < len; ++i)
        {
            *p1 = *p2;
            ++p1;
            ++p2;
        }
    }
    return s1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    const char* p1 = s1,* p2 = s2;
    do
    {
        if (*p1 == *p2)
        {
            ++p1;
            ++p2;
        }
        else
            return  *p1 - *p2;
    } while (*(p1-1) != '\0' && *(p2-1) != '\0');
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    const char* p1 = s1, * p2 = s2;
    int a, b;
    do
    {
        if (*p1>= 65 && *p1 <= 90)
            a = 32 + *p1;
        else
            a = *p1;
        if (*p2 >= 65 && *p2 <= 90)
            b = 32 + *p2;
        else
            b = *p2;
        if (a == b)
        {
            ++p1;
            ++p2;
        }
        else
            return a - b;
    } while (*(p1 - 1) != '\0' && *(p2 - 1) != '\0');
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    const char* p1 = s1, * p2 = s2;
    int s1len, s2len;
    s1len = tj_strlen(s1);
    s2len = tj_strlen(s2);
    do
    {
        if (*p1 == *p2)
        {
            ++p1;
            ++p2;
        }
        else
            return *p1 - *p2;
    } while ((p1-s1 - 1) != s1len && (p1 - s1 - 1) != s2len && (p1 - s1) != len);
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return -1;
    if (s2 == NULL)
        return 1;
    const char* p1 = s1, * p2 = s2;
    int s1len, s2len, a, b;
    s1len = tj_strlen(s1);
    s2len = tj_strlen(s2);
    do
    {

        if (*p1 >= 65 && *p1 <= 90)
            a = 32 + *p1;
        else
            a = *p1;
        if (*p2 >= 65 && *p2 <= 90)
            b = 32 + *p2;
        else
            b = *p2;
        if (a == b)
        {
            ++p1;
            ++p2;
        }
        else
            return a - b;
    } while ((p1 - s1 - 1) != s1len && (p1 - s1 - 1) != s2len && (p1 - s1) != len);
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strupr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    char* p = str;
    while (*p != '\0')
    {
        if (*p >= 97 && *p <= 122)
            *p -= 32;
        ++p;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    char* p = str;
    while (*p != '\0')
    {
        if (*p >= 65 && *p <= 90)
            *p += 32;
        ++p;
    }
    return str;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    const char* p = str;
    while (*p != '\0')
    {
        if (*p == ch)
            return p-str+1;
        ++p;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    if (substr == NULL)
        return NULL;
    const char* p1 = str, * p2 = substr;
    int i = 0;
    bool abc = 0;
    while (*p1 != '\0')
    {
        if (*p1 == *p2)
            for (int j = 0; j < tj_strlen(substr); ++j)
            {
                if (*(p1+j) == *(p2+j))
                    abc = 1;
                else
                    abc = 0;
            }
        if (abc == 1)
            return p1-str + 1;
        ++p1;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    int slen;
    slen = tj_strlen(str);
    const char* p=str+slen-1;
    for (int i = 0; i < slen; ++i)
    {
        if (*p == ch)
            return p-str+1;
        --p;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;
    if (substr == NULL)
        return NULL;
    int slen;
    bool abc = 0;
    slen = tj_strlen(str);
    const char* p1=str+slen-1, * p2 = substr;
    for(int i=0;i<slen;++i)
    {
        if (*p1 == *p2)
            for (int j = 0; j < tj_strlen(substr); ++j)
            {
                if (*(p1 + j) == *(p2 + j))
                    abc = 1;
                else
                    abc = 0;
            }
        if (abc == 1)
            return p1 - str + 1;
        --p1;
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char* tj_strrev(char* str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL)
        return NULL;

    int slen;
    char fuzhu;

    slen = tj_strlen(str);
    char* p1 = str, * p2 = str + slen-1;

    for (int i = 0; i < slen / 2; ++i)
    {
        fuzhu = *p1;
        *p1 = *p2;
        *p2= fuzhu;
        ++p1;
        --p2;
    }

    return str;
}