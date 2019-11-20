ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    // check if list if null, if yes, return other list directory
    if(pHead1 == NULL)
        return pHead2;
    else if(pHead2 == NULL)
        return pHead1;

    // define combine list new node
    ListNode* pMergedHead = NULL;

 
    // compare list value in two list , then run merge continue
    if(pHead1->value < pHead2->value)
    {
        pMergedHead = pHead1;
        pMergedHead->next = Merge(pHead1->next, pHead2);
    }
    else
    {
        pMergedHead = pHead2;
        pMergedHead->next = Merge(pHead1, pHead2->next);
    }

    return pMergedHead;
}


