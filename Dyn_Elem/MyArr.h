
class MyArr
{
  private: 
    double *arr;
    int max;
    int len;
    void expand(int size);

  public:
    MyArr(int n=256);
    MyArr(int n, double x);
    MyArr(const MyArr &a);
    ~MyArr();
    int length() const {return len;}
    friend ostream &operator<<(ostream &os, MyArr &a);
    MyArr &operator=(const MyArr &a);
    double& operator[](int i);
    double operator[](int i) const;
    void append(double x);
    void append(const MyArr & a);
    bool remove(int pos);
    bool insert(double x, int pos);    
    bool insert(const MyArr &a, int pos);
};