#include <iostream>
#include "reverse_linked_list.hpp"

Node *create_counting_linked_list(int size_of_list)
{
    Node *new_counting_list = new Node(0);
    Node *current_position = new_counting_list;
    for (int i = 1; i < size_of_list; i++)
    {
        current_position->next = new Node(i);
        current_position = current_position->next;
    }

    return new_counting_list;
}
int main()
{
    Node *head = create_counting_linked_list(5);
    Node *func;
    std::cout << "Original List: ";
    func->print_list(head);
    func->reverse_linked_list(head);
    std::cout << "Reversed List: ";
    func->print_list(head);

    return 0;
}