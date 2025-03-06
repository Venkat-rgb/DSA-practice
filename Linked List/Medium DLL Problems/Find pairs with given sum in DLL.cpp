Node *findTail(Node *head) {
    while(head -> next != NULL) {
        head = head -> next;
    }
    return head;
}

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector <pair <int,int>> res;
    
    if(head == NULL || head -> next == NULL) {
        return res;
    }
    
    Node *start = head, *end = findTail(head);
    
    while(start -> data < end -> data) {
        int sum = start -> data + end -> data;
        
        if(sum == target) {
            res.push_back({start -> data, end -> data});
            start = start -> next;
            end = end -> prev;
        }
        else if(sum > target) {
            end = end -> prev;
        }
        else {
            start = start -> next;
        }
    }
    
    return res;
}