#include<iostream>
#include<vector>

class matrix_threeD
{
private:
    int length;
    int width;
    int depth;
    std::vector<int> matrix;
    int calc_index( int x, int y, int z ) {
        return (z * length * width) + (y * length) + x;
    }
public:
    matrix_threeD(int l, int w, int d){
        length = l;
        width = w;
        depth = d;
        matrix.resize(l*w*d);
    }
    int read_matrix(int x, int y, int z){
        return matrix[calc_index(x,y,z)];
    }
    void write_matrix( int x, int y, int z, int value ) {
         matrix[calc_index(x,y,z)] = value;
    }


    ~matrix_threeD(){
        matrix.clear();
    }

};


int main()
{
    matrix_threeD m(3,3,3);
    m.write_matrix(0,0,0,1);
    m.write_matrix(1,1,1,2);
    std::cout<<m.read_matrix(0,0,0);
    std::cout<<m.read_matrix(1,1,1);
}