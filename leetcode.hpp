#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int new_data)
    {
        data = new_data;
        next = nullptr;
    }
    void reverse_linked_list(Node *&head);
    void print_list(Node *head);
};

void Node::reverse_linked_list(Node *&head)
{
    Node *curr_pos;
    Node *next_pos;
    Node *prev_pos;

    prev_pos = head;
    curr_pos = prev_pos->next;
    next_pos = curr_pos->next;
    prev_pos->next = nullptr;

    int count = 0;
    std::cout << prev_pos->data << " " << curr_pos->data << " " << next_pos->data << std::endl;
    while (next_pos != nullptr)
    {
        curr_pos->next = prev_pos;
        prev_pos = curr_pos;
        // std::cout << prev_pos->data << " " << curr_pos->data << " " << next_pos->data << std::endl;
        curr_pos = next_pos;
        // std::cout << prev_pos->data << " " << curr_pos->data << " " << next_pos->data << std::endl;
        // std::cout << prev_pos->data << " " << curr_pos->data << " ";
        next_pos = next_pos->next;
        // std::cout << next_pos->data << std::endl;
    }
    // std::cout << prev_pos->data << " " << curr_pos->data << " " << next_pos->data << std::endl;
    curr_pos->next = prev_pos;
    std::cout << curr_pos->data << std::endl;
    head = curr_pos;
}

void Node::print_list(Node *head)
{
    Node *current_pos = head;
    while (current_pos != nullptr)
    {
        std::cout << current_pos->data << " ";
        current_pos = current_pos->next;
    }
    std::cout << std::endl;
}