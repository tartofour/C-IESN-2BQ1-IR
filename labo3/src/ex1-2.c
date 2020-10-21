struct rectangle
{
    int length;
    int width;
};

struct dog
{
    char name[10];
    unsigned char age;
    unsigned char weight;
    char gender;
};

int main (void)
{
    struct rectangle r = {2,5};
    struct dog d = {"Pipi", 6, 5, 'M'};
}
