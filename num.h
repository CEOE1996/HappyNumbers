#ifndef NUM_H_INCLUDED
#define NUM_H_INCLUDED

class Num{
    private:
        short N;

    public:
        Num();
        Num(const short&);

        void setN(const short&);

        short getN();

        short Square();

        bool IsPrimo();

};

#endif // NUM_H_INCLUDED
