#include <iostream>

using namespace std;

class Safe
{
  private:
    int topSecret;
  protected:
    int secret;
    void setTopSecret(int n) {topSecret = n;}
    int getTopSecret() const {return topSecret;}
    void setSecret(int n) {secret = n;}
    int getSecret() const {return secret;}
  public:
    int notSecret;
    Safe()
    {topSecret=69, secret=78, notSecret=0;}
};

class Castle: public Safe
{
  public:
    Castle()
    {
        
    }  
};