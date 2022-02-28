/*构建一个链表需要：构建链表结构体，
 *链表初始化、析构，得到链表的长度，
 *插入，删除，查询，改变，打印所有数据。
*/
typedef struct _node
{
    int data;
    _node *next;
}node;

class linkList
{
private:
    int length;
    node *head; //head为头结点，不存储数据,不计入长度
public:
    linkList();
    ~linkList();

    int getlen();
    void insertList(int position, int elem);
    int deleteList(int position);
    int queryList(int position);
    void changeList(int position, int elem);
    void printList();
};
