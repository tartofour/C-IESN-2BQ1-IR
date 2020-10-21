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

typedef struct dog Dog;

int main(void)
{
    struct person person1 = {"Benjamin", "Verjus", "Rue d'Esch sur Alzette, 17, 4000 Liège", {7, 4, 1992}};
    Dog dog1 = {"Pipi", 6, 5, 'M', person1};
}
