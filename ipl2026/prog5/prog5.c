#include <stdio.h>

union decision
{
    unsigned char flags;

    struct field
    {
        unsigned int your_choice           : 1;
        unsigned int your_mothers_choice  : 1;
        unsigned int your_fathers_choice  : 1;
        unsigned int socially_acceptable  : 1;
        unsigned int financially_viable   : 1;
        unsigned int do_you_aptitude      : 1;
        unsigned int do_you_likeit        : 1;
        unsigned int final_decision       : 1;

    } field;
};

union decision input();

void make_decision(union decision *d);

void print_decision(union decision d);

void print_conclusion_based_on_flags(union decision d);

void printBits(unsigned char n)
{
    int i;

    for(i = 7; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);
    }

    printf("\n");
}

union decision input()
{
    union decision d;

    d.flags = 0;

    printf("Enter your choice (0/1): ");
    scanf("%u", &d.field.your_choice);

    printf("Enter your mother's choice (0/1): ");
    scanf("%u", &d.field.your_mothers_choice);

    printf("Enter your father's choice (0/1): ");
    scanf("%u", &d.field.your_fathers_choice);

    printf("Is it socially acceptable? (0/1): ");
    scanf("%u", &d.field.socially_acceptable);

    printf("Is it financially viable? (0/1): ");
    scanf("%u", &d.field.financially_viable);

    printf("Do you have aptitude? (0/1): ");
    scanf("%u", &d.field.do_you_aptitude);

    printf("Do you like it? (0/1): ");
    scanf("%u", &d.field.do_you_likeit);

    return d;
}

void make_decision(union decision *d)
{
    d->field.final_decision =
    (
        d->field.your_choice &&
        d->field.do_you_likeit &&
        d->field.do_you_aptitude &&
        d->field.financially_viable
    );
}

void print_decision(union decision d)
{
    printf("\n------ Decision Report ------\n");

    printf("Your Choice           : %u\n", d.field.your_choice);

    printf("Mother's Choice       : %u\n", d.field.your_mothers_choice);

    printf("Father's Choice       : %u\n", d.field.your_fathers_choice);

    printf("Socially Acceptable   : %u\n", d.field.socially_acceptable);

    printf("Financially Viable    : %u\n", d.field.financially_viable);

    printf("You Have Aptitude     : %u\n", d.field.do_you_aptitude);

    printf("You Like It           : %u\n", d.field.do_you_likeit);

    printf("Final Decision        : %u\n", d.field.final_decision);

    if(d.field.final_decision)
    {
        printf("\nNarrative:\n");
        printf("You should proceed with this decision.\n");
    }
    else
    {
        printf("\nNarrative:\n");
        printf("This decision may not be suitable right now.\n");
    }
}

void print_conclusion_based_on_flags(union decision d)
{
    printf("\n------ Flag Analysis ------\n");

    printf("Flags Decimal Value = %u\n", d.flags);

    printf("Flags Binary Value  = ");

    printBits(d.flags);

    if(d.flags == 255)
    {
        printf("Perfect alignment in all factors.\n");
    }
    else if(d.flags >= 200)
    {
        printf("Very strong positive decision profile.\n");
    }
    else if(d.flags >= 100)
    {
        printf("Moderately balanced decision profile.\n");
    }
    else if(d.flags >= 50)
    {
        printf("Mixed signals detected in decision making.\n");
    }
    else
    {
        printf("Weak support for this decision.\n");
    }
}

int main()
{
    union decision d;

    d = input();

    make_decision(&d);

    print_decision(d);

    print_conclusion_based_on_flags(d);

    return 0;
}