

#include <iostream.h>
#define LIMIT      3

using namespace std;

#define MIN_LEN     1

/* Helper function to demonstrate implementation of standard strlen */
int my_str_len(const char * s)
{
    const char *temp;
    for(temp = s; *temp!='\0'; ++temp);
    return temp-s;
}

/* reverse in place pointer notation */
void string_reverse3(char *string)
{
/* your code here */

    char *start, *end;
    start = end = string;

    while(*(++end));

    if (start == end || start+1 == end)
        return;

    for(;start < --end; ++start)
    {
        char temp = *start;
        *start = *end;
        *end = temp;
    }
}



/* Reverses string in place. The caller is responsible for allocating / deallocating memory in passed char array. */
void string_reverse1(char *string)
{
/* your code here */

    int size = my_str_len(string);
    int index;

    for(index = 0; index < size/2; index++)
    {
        char temp = string[index];
        string[index] = string[size-index-1];
        string[size-index-1] = temp;
    }

}

/* Creates a copy of passed string with elements reversed. Malloc is used for allocation because pointer
 * to local array cannot be returned. Secondly, static array cannot be created when size is determined
 * on run time. The caller is responsible for freeing the memory.
 */
char *string_reverse2(const char *string)
{
/* your code here */

    int index = 0;
    char * reversed_str;
    int size = my_str_len(string);

    if (size < MIN_LEN)
        return NULL;

    /* Add 1 for terminating null character */
    reversed_str = (char *) malloc(sizeof(char) * (size+1));

    if (!reversed_str)
        return NULL;

    for (;size > 0; size--, index++)
    {
        reversed_str[index] = string[size-1];
    }

    reversed_str[index] = '\0';

    return reversed_str;
}

int main()
{
char s1[80],rev[80];
int len,i,j;
printf("enter string=");

scanf("%s", s1);
len = strlen(s1);
for(i=strlen(s1)-1,j=0;i>=0;i--,j++)
{
    rev[j]=s1[i];
}
rev[j]='\0';

strcat(s1,rev);
printf("palindrome=\n%s\0",s1);

    //char str[100] = "abcd";
    //char * temp;
    //temp = string_reverse2(str);

    //if(temp != NULL)
    //{
    //    cout << "reversed using array\n" << temp << endl;
    //    free(temp);
    //}

    //else
    //    cout << "Either passed string is null or failed to allocate memory" << endl;
    ////cout << str << endl;

    //string_reverse3(str);

    //cout << "reversed using pointers\n" << str << endl;
    getchar();
    return 0;
}


