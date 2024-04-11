#include <iostream>

class vector
{
public:
    vector();
    vector(float x, float y, float z) : x(x), y(y), z(z) {}
    
    float length() const;
    float length_sqr() const;
    static float dot_product(const vector& a, const vector& b);

    vector operator+(const vector& v) const;
    vector operator-(const vector& v) const;

    vector operator*(float s) const;
    vector operator/(float s) const;

    vector normalized() const;
    
public:
    float x,y,z;
};

class point
{
public:
    point add_vector(vector v) const;

    vector get_vector(){return {x,y,z};}
    vector get_normalized_vector(){return get_vector().normalized();}
    float x,y,z;
};

vector::vector()
{
    x = 0;
    y = 0;
    z = 0;
}

float vector::length() const
{
    return sqrt(x*x + y*y + z*z);
}
float vector::length_sqr() const
{
    return x*x + y*y + z*z;
}

float vector::dot_product(const vector& a, const vector& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

vector vector::operator+(const vector& v) const
{
    vector added_vector;
    added_vector.x = x + v.x;
    added_vector.y = y + v.y;
    added_vector.z = z + v.z;
    return added_vector;
}

vector vector::operator-(const vector& v) const
{
    return {x - v.x, y - v.y, z - v.z};
}

vector vector::operator*(float s) const
{
    vector scaled_vector;
    scaled_vector.x = x * s;
    scaled_vector.y = y * s;
    scaled_vector.z = z * s;
    return scaled_vector;
}

vector vector::operator/(float s) const
{
    vector scaled_vector;
    scaled_vector.x = x / s;
    scaled_vector.y = y / s;
    scaled_vector.z = z / s;
    return scaled_vector;
}

vector vector::normalized() const
{
    const vector normalized_vector = *this / length();
    
    return normalized_vector;
}

vector operator-(point a, point b) //operator overloading - for vector
{
    vector v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    v.z = a.z - b.z;
    return v;
}
point point::add_vector(vector v) const
{
    point p2;
    p2.x = x + v.x;
    p2.y = y + v.y;
    p2.z = z + v.z;
    return p2;
}

int main(int argc, char* argv[])
{
    point pac_man; // (0,-1,0)
    pac_man.x = 0;
    pac_man.y = -1;
    pac_man.z = 0;

    point inky; // (1,1,0)
    inky.x = 1;
    inky.y = 1;
    inky.z = 0;

    point clyde; // (2, -1, 0)
    clyde.x = 2;
    clyde.y = -1;
    clyde.z = 0;

    // vector from i to p
    const vector vector_inky_to_pacman = pac_man - inky;    // to get point i to point p

    // vector from c to p and i to p
    const vector clyde_to_pacman = pac_man - clyde;
    const vector inky_to_pacman = pac_man - inky;

    const float length_sqr_cp = clyde_to_pacman.length_sqr();
    const float length_sqr_ip = inky_to_pacman.length_sqr();

    const point pacman_new_point = pac_man.add_vector(vector_inky_to_pacman);  // final point

    const float length = vector_inky_to_pacman.length(); // length of vector

    const float length_sqr = vector_inky_to_pacman.length_sqr(); // length of vector squared

    const vector pac_man_pos1(3,4,0); // vector (3,4,0)

    const vector scaled_vector = pac_man_pos1 * 2; // scaling the vector by 2

    const vector scaled_halved = pac_man_pos1 / 2; // scaling the vector by 2

    const vector position_pacman_to_inky = inky - pac_man;

    const vector normalized_direction = position_pacman_to_inky.normalized();

    const vector right_vector = {5,0,0};
    const vector down_vector = {0,-5,0};
    const vector up_vector = {0,5,0};
    const vector left_vector = {-5,0,0};

    const vector new_velocity = right_vector + down_vector;

    const vector view_vector;
    const vector pac_man_vector = up_vector.normalized();
    const vector inky_vector = down_vector.normalized();

    vector if_backstabbing = (inky - pac_man).normalized();
    // if -1 then backstabbing if 1 then facing each other if 0 then perpendicular
    
    
    /*Declaration of variables for debugging
     *
     *std::cout << "Vector: (" << vector_inky_to_pacman.x << "," << vector_inky_to_pacman.y << "," << vector_inky_to_pacman.z << ")" << '\n';
     *std::cout << "Point: (" << pacman_new_point.x << "," << pacman_new_point.y << "," << pacman_new_point.z << ")" << '\n';
     *std::cout << "Length: " << length << '\n';
     *std::cout << "Length Squared: " << length_sqr << '\n';
     *std::cout << "Length Squared cp: " << length_sqr_cp << '\n';
     *std::cout << "Length Squared ip: " << length_sqr_ip << '\n';
     * 
     */

    /* Testing the functions
     * 
    std::cout << "Pac man's initial speed: " << pac_man_pos1.length() << '\n';
    std::cout << "Pac man's speed after eating a power pellet: " << scaled_vector.length() << '\n';
    std::cout << "Pac man's speed after eating a power pellet and halving it: " << scaled_halved.length() << '\n';
    std::cout << "Pac man's view vector: (" << normalized_direction.x << "," << normalized_direction.y << "," << normalized_direction.z << ")" << '\n';
    std::cout << "Pac man's view vector length: " << normalized_direction.length() << '\n';
    std::cout << "Pac man's new velocity: (" << new_velocity.x << "," << new_velocity.y << "," << new_velocity.z << ")" << '\n';
    */

    
    
    return 0;
}
