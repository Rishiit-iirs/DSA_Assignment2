#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int coefficient;
    int exponent;
    Node *next;
};

void mergeNodes(Node *head);
void displayPolynomial(Node *ptr);
Node *appendNode(Node *start, int coefficient, int exponent);

Node *multiplyPolynomialLL(Node *head1, Node *head2,Node *head3)
{

    /* declare ptr1 and ptr2 to iterate over the two polynomials */
    Node *ptr1, *ptr2;
    ptr1 = head1;
    ptr2 = head2;
    while (ptr1 != NULL)
    {
        while (ptr2 != NULL)
        {
            int coeff, exponent;
            /*multiply the coefficients*/
            coeff = ptr1->coefficient * ptr2->coefficient;
            /* add the exponents*/
            exponent = ptr1->exponent + ptr2->exponent;
            /*create and append a new node to the product list */
            head3 = appendNode(head3, coeff, exponent);

            // update ptr2 to point to next node
            ptr2 = ptr2->next;
        }
        // reset ptr2 to point to head2
        ptr2 = head2;

        // update ptr1 to point to next node
        ptr1 = ptr1->next;
    }

    /* call this function to merge the nodes having same exponent value */
    mergeNodes(head3);
    return head3;
}

// function to print the linked list as a polynomial
void displayPolynomial(Node *ptr)
{
    while (ptr->next != NULL)
    {
        if (ptr->coefficient != 0 && ptr->coefficient != 1)
        {
            if (ptr->exponent != 0 && ptr->exponent != 1)
                cout << ptr->coefficient << "x^" << ptr->exponent;
            else if (ptr->exponent == 1)
                cout << ptr->coefficient << "x";
            else
                cout << ptr->coefficient;
        }
        else if (ptr->coefficient == 1)
        {

            if (ptr->exponent != 0 && ptr->exponent != 1)
                cout << "x^" << ptr->exponent;
            else if (ptr->exponent == 1)
                cout << "x";
            else
                cout << ptr->coefficient;
        }
        if (ptr->next != NULL && ptr->next->coefficient >= 0)
            cout << "+";

        ptr = ptr->next;
    }
    cout << ptr->coefficient << "\n";
}

// function to add a new term to a polynomial in the linked list
Node *appendNode(Node *start, int coefficient, int exponent)
{
    // create a new node
    Node *newnode = new Node;
    newnode->coefficient = coefficient;
    newnode->exponent = exponent;
    newnode->next = NULL;

    // if the linked list is empty
    if (start == NULL)
        return newnode;

    Node *ptr = start;
    // iterate till the last node
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = newnode;

    return start;
}

/* function to add the coefficients of the terms having equal coefficients
in the linked list */
void mergeNodes(Node *head)
{
    Node *ptr1, *ptr2, *dup;
    ptr1 = head;

    /* iterate over the nodes*/
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        /*compare the current node's exponent with the other nodes */
        while (ptr2->next != NULL)
        {
            if (ptr1->exponent == ptr2->next->exponent)
            {
                // add the coefficients
                ptr1->coefficient = ptr1->coefficient + ptr2->next->coefficient;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;

                /* delete this node as its coefficient has been added */
                delete (dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

int main()
{

    Node *head1, *head2, *head3;
    head1 = head2 = head3 = NULL;
    /*P(x) =  4x² − 5x + 9*/
    head1 = appendNode(head1, 4, 2);
    head1 = appendNode(head1, -5, 1);
    head1 = appendNode(head1, 9, 0);
    /*Q(x) =  3x3 − 10x2 + 9x + 1*/
    head2 = appendNode(head2, 3, 3);
    head2 = appendNode(head2, -10, 2);
    head2 = appendNode(head2, 9, 1);
    head2 = appendNode(head2, 1, 0);

    head3 = multiplyPolynomialLL(head1, head2, head3);

    cout << "P(x) = ";
    displayPolynomial(head1);
    cout << "Q(x) = ";
    displayPolynomial(head2);
    cout << "P(x)*Q(x) = ";
    displayPolynomial(head3);

    return 0;
}