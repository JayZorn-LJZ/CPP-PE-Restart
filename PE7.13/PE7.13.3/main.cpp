#include <iostream>

using namespace std;

struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_box(box);
void fill_volume(box *);

int main(void)
{
    box b {
        "hello",
        10.3,
        10.3,
        10.3,
        0
    };

    fill_volume(&b);
    show_box(b);

    return 0;
}

void show_box(box b)
{
    cout << "Height: " << b.height << endl;
    cout << "width: " << b.width << endl;
    cout << "length: " << b.length << endl;
    cout << "volume: " << b.volume << endl;
}

void fill_volume(box * b_p)
{
    b_p->volume = b_p->height * b_p->width * b_p->length;
}