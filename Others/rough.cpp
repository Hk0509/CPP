private:
    Node* getMid(Node* head)
    {
       Node* fast = head -> next;
       Node* slow = head;

       while(fast != NULL && fast -> next != NULL)
       {
           fast = fast -> next;
           if(fast -> next != NULL)
           {
           fast = fast -> next;
           }
           slow = slow -> next;
       }
       return slow;
    }

    Node* rev(Node* temp)
    {   
        Node* curr = temp;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr != NULL)
        {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(Node* head) {
        if(head == NULL || head -> next == NULL)
        return true;

        //Get mid
        Node* mid = getMid(head);
        cout<<mid->data<<endl;

        //Reverse second half
        Node* temp = mid -> next;
        mid -> next = rev(temp);

        //Compare both halves
        Node* head1 = head;
        Node* head2 = mid -> next;

        while(head2 != NULL)
        {
            if(head1 -> data != head2 -> data)
            return 0;
            head1 = head1 -> next;
            head2 = head2 -> next;
        }

        temp = mid -> next;
        mid -> next = rev(temp);

        return 1;
    }