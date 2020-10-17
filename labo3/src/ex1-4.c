struct date 
{
    int day;
    int month;
    int year;
};

struct person
{
    char first_name[10];
    char last_name[10];
    char address[50];
    struct date birth_date;
};

struct dog
{
    char name[10];
    unsigned char age;
    unsigned char weight;
    char gender;
    struct person owner;
};

int main(void)
{
    struct person person1 = {"John", "Doe", "Rue de la résistance, 17, 4000 Liège", {17, 2, 1987}};
}
