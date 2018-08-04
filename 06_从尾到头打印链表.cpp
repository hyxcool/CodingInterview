输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

//////////总结

1.value.insert(value.begin(),head->val);
递归语句，注意在递归函数前后的语句区别
递归注意return

2.迭代方法关键 push(),top(),pop()
            nodes.push(pNode);
            pNode=nodes.top();
            ArrayList.push_back(pNode->val);
            nodes.pop();
            
            
//////////////////////////////////////////////////方法1：堆栈
class Solution 
{
public:
     
    vector<int> printListFromTailToHead(ListNode* head)
    {
        vector<int> ArrayList;
        stack<ListNode*> nodes;
        ListNode* pNode=head;
        while(pNode!=nullptr)
        {
            nodes.push(pNode);
            pNode=pNode->next;
        }
        while(!nodes.empty())
        {
            pNode=nodes.top();
            ArrayList.push_back(pNode->val);
            nodes.pop();
        }
        return ArrayList;
    }
};
/////////////////////////////////////////////////方法2：递归

//////////////////////////////////////////////////方法2-1   有return ArrayList的递归要注意，可能递归到最后一步就return结束了
class Solution {
public:
    vector<int> ArrayList;
    void help(ListNode* head)
    {
        if (head != nullptr)
        {
            if (head->next != nullptr)
            {
                printListFromTailToHead(head->next);
            }
            ArrayList.push_back(head->val);
        }
    }
    vector<int> printListFromTailToHead(ListNode* head)
    {
        help(head);
        return ArrayList;
    }
};


////////////////////////////////////////////////////////////方法2-1 printf打印输出的直接递归
class Solution {
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != nullptr)
    {
        if (pHead->m_pNext != nullptr)
        {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
 
        printf("%d\t", pHead->m_nValue);
    }
}

/////////////////////////////////////////////////方法3：迭代
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> value;
        if (head != NULL)
        {
            value.insert(value.begin(), head->val);
            while (head->next != NULL)
            {
                value.insert(value.begin(), head->next->val);
                head = head->next;
            }

        }
        return value;
    }
};

///////////////////////////////////////////////////////////////////////////////////////////牛客网参考解析
方法一：链表从尾到头输出，利用递归实现，不使用库函数直接printf输出的时候用递归比较好
（该方法还未理解）这边的return和上边方法1递归的区别？

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> value;
        if(head != NULL)
        {
            value.insert(value.begin(),head->val);
            if(head->next != NULL)
            {
                vector<int> tempVec = printListFromTailToHead(head->next);
                if(tempVec.size()>0)
                value.insert(value.begin(),tempVec.begin(),tempVec.end());  
            }         
             
        }
        return value;
    }
};

//////
方法二：用库函数，每次扫描一个节点，将该结点数据存入vector中，如果该节点有下一节点，
将下一节点数据直接插入vector最前面，直至遍历完，或者直接加在最后，最后调用reverse

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(struct ListNode* head) {
        vector<int> value;
        if(head != NULL)
        {
            value.insert(value.begin(),head->val);
            while(head->next != NULL)
            {
                value.insert(value.begin(),head->next->val);
                head = head->next;
            }         
             
        }
        return value;
    }
};
