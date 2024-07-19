#include <iostream>
#define first*;
struct Node
{
	int info;
	Node*link;
};
struct DSLienKetDon
{
	Node *head;
};
//Khoi tao danh sach//
void init(DSLienKetDon &lkd)
{
	lkd.head = NULL;
}
