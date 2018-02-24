#include<iostream>
#include<cstdlib>
#include<ctime>
#include <random>
#define liter 10

class word
{
private:
    std::size_t N;
    char* lit;
public:
    word();
    word(const std::size_t& N);
    word(const std::size_t& N, std::mt19937& genrand);

    ~word();
    void setup( std::size_t sizeword,std::mt19937& genrand );
    void display();
};
void word::display()
{
    for ( auto i = 0; i < this->N; ++i ) {
    std::cout << this->lit[i];
    }
}
void word::setup( std::size_t sizeword,std::mt19937& genrand ){
        std::uniform_real_distribution<> disr(int('a'),int('z'));
    std::uniform_real_distribution<> distr(int('A'),int('Z'));
    this->N = sizeword;
    this->lit = new char [N];
    this->lit[0] = char(distr(genrand));
    for ( auto i = 1; i < this->N; ++i ) {
            this->lit[i] = char(disr(genrand));
        }
}
word::word()
{
    this->N = 0;
    this->lit = nullptr;
}

word::word(const std::size_t& N)
{
    this->N = N;
    this->lit = new char [N];
}
word::word(const std::size_t& N, std::mt19937& genrand)
{
    std::uniform_real_distribution<> disr(int('a'),int('z'));
    std::uniform_real_distribution<> distr(int('A'),int('Z'));
    this->N = N;
    this->lit = new char [N];
    this->lit[0] = char(distr(genrand));
    for ( auto i = 1; i < this->N; ++i ) {
            this->lit[i] = char(disr(genrand));
        }
}

word::~word()
{
    if ( this->N != 0 ) {
        delete [] lit;
        this->lit = nullptr;
    }
}

int main(){
    constexpr std::size_t N = liter;
    std::mt19937 genr(time(0));
    word a(N,genr);
    word b;
    b.setup(10,genr);
    a.display();
    std::cout<<std::endl;
    b.display();
}
