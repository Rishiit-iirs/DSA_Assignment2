#include <stdio.h>
#include<stdlib.h>
struct Term
{
    int coeff;
    int exp;
};
struct Poly
{
    int n;
    struct Term *terms;
};
void create (struct Poly *p)
{
    int i;
    printf ("Enter Number of terms: ");
    scanf ("%d", &p->n);
    p->terms = (struct Term *) malloc (p->n * sizeof (struct Term));
    printf ("Enter terms:\n");
    for (i = 0; i < p->n; i++)
        scanf ("%d^%d", &p->terms[i].coeff, &p->terms[i].exp);
    printf ("\n");
}
void display (struct Poly p)
{
    int i;
    for (i = 0; i < p.n; i++)
    {
        printf ("%dx^%d", p.terms[i].coeff, p.terms[i].exp);
        if (i + 1 < p.n)
         printf (" + ");
    }
    printf ("\n");
}

int main()
{
    struct Poly p1, p2;
    printf ("Enter Polynomial 1:\n");
    create (&p1);
    printf ("Enter Polynomial 2:\n");
    create (&p2);

    printf ("Polynomial 1 is: ");
    display (p1);
    printf ("\n");
    printf ("Polynomial 2 is: ");
    display (p2);
    printf ("\n");

    return 0;

}
