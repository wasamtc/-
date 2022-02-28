/*用链式存储结构构造栈，先构建链表的结点，然后构造栈类和相应的函数。*/

//链表结点的结构体，包含数据和指向下一个结点的指针
struct node
{
    int data;
    node *next;
};

//栈类，在头结点处进行入栈和出栈，数据主要由头结点，长度，函数主要有入栈，出栈，获取长度，查询，打印。
class linkStack
{
private:
    node *head;
    int length;
public:
    linkStack();
    ~linkStack();

    void pushStack(int data);
    int popStack();

    int getlen();
    int queryStack(int position);
    void printStack();
};

