#include <iostream>
using namespace std;

const string operator * (const string& leftStr, const string& rightStr);
const string operator / (const string& leftStr, const string& rightStr);
const string operator - (const string& leftStr, const string& rightStr);

class var
{
private:
    int* chislo;
    double* drob;
    string* stroka;
    int num; 
public:
    var() { num = -1; chislo = NULL; drob = NULL; stroka = NULL; };
    var(const int& number);
    var(const double& number);
    var(const string& str);
    void Show();
    int chl()const;
    double dr()const;
    char* chr()const;
    const string str()const;
    var& operator = (const var& rightVar);
    var& operator = (const int& number);
    var& operator = (const double& number);
    var& operator = (const string& str);
    const var operator + (const var& rightVar);
    const var operator - (const var& rightVar);
    const var operator * (const var& rightVar);
    const var operator / (const var& rightVar);
    var& operator += (const var& rightVar);
    var& operator -= (const var& rightVar);
    var& operator *= (const var& rightVar);
    var& operator /= (const var& rightVar);
    bool operator < (const var& rightVar);
    bool operator > (const var& rightVar);
    bool operator <= (const var& rightVar);
    bool operator >= (const var& rightVar);
    bool operator == (const var& rightVar);
    bool operator != (const var& rightVar);
};

var::var(const int& number)
{
    num = 0;
    chislo = new int(number);
}

var::var(const double& number)
{
    num = 1;
    drob = new double(number);
}

var::var(const string& str)
{
    num = 2;
    stroka = new string(str);
}

void var::Show()
{
    switch (num)
    {
    case 0: cout << *chislo; return;
    case 1: cout << *drob; return;
    case 2: cout << *stroka; return;
    }
    cout << "NULL";
}
int var::chl() const
{
    switch (num)
    {
    case 0: return *chislo;
    case 1: return (int)*drob;
    case 2: return atoi((*stroka).c_str());
    }
    return 0;
}

double var::dr() const
{
    switch (num)
    {
    case 0: return (double)*chislo;
    case 1: return *drob;
    case 2: return (double)atof((*stroka).c_str());
    }
    return 0;
}

char* var::chr() const
{
    char* tmpStr = new char[80];
    switch (num)
    {
    case 0:
        return itoa(*chislo, tmpStr, 10);
    case 1:
        sprintf(tmpStr, "%lf", *drob);
        return tmpStr;
    case 2:
        strcpy(tmpStr, (*stroka).c_str());
        return tmpStr;
    }
    return NULL;
}

const string var::str() const
{
    if (num == 2)
    {
        return string(*stroka);

    }
    return string(toCharPtr());


}

const var var::operator - (const var& rightVar)
{
    switch (num)
    {
    case 0:
        return var(*chislo - rightVar.chl());
    case 1:
        return var(*drob - rightVar.dr());

    case 2:
        return var(*stroka - rightVar.str());

    }
    return *this;
}

const var var::operator + (const var& rightVar)
{
    switch (num)
    {
    case 0:
        return var(*chislo + rightVar.chl());

    case 1:
        return var(*drob + rightVar.dr());

    case 2:
        return var(*stroka + rightVar.str());

    }
    return *this;
}

const var var::operator * (const var& rightVar)
{
    switch (num)
    {
    case 0:
        return var(*chislo * rightVar.chl());

    case 1:
        return var(*drob * rightVar.dr());

    case 2:
        return var(*stroka * rightVar.str());

    }
    return *this;
}

const var var::operator / (const var& rightVar)
{
    switch (num)
    {
    case 0:
        return var(*chislo / rightVar.chl());

    case 1:
        return var(*drob / rightVar.dr());

    case 2:
        return var(*stroka / rightVar.str());

    }
    return *this;
}

var& var::operator += (const var& rightVar)
{
    switch (num)
    {
    case 0:
        *chislo = *chislo + rightVar.chl();
        return *this;
    case 1:
        *drob = *drob + rightVar.dr();
        return *this;
    case 2:
        *stroka = *stroka + rightVar.str();
        return *this;
    }
    return *this;
}

var& var::operator -= (const var& rightVar)
{
    switch (num)
    {
    case 0:
        *chislo = *chislo - rightVar.chl();
        return *this;
    case 1:
        *drob = *drob - rightVar.dr();
        return *this;
    case 2:
        *stroka = *stroka - rightVar.str();
        return *this;
    }
    return *this;
}

var& var::operator *= (const var& rightVar)
{
    switch (num)
    {
    case 0:
        *chislo = *chislo * rightVar.chl();
        break;
    case 1:
        *drob = *drob * rightVar.dr();
        break;
    case 2:
        *stroka = *stroka * rightVar.str();
        break;
    }
    return *this;
}

var& var::operator /= (const var& rightVar)
{
    switch (num)
    {
    case 0:
        *chislo = *chislo / rightVar.chl();
        break;
    case 1:
        *drob = *drob / rightVar.dr();
        break;
    case 2:
        *stroka = *stroka / rightVar.str();
        break;
    }
    return *this;
}

bool var::operator > (const var& rightVar)
{
    switch (num)
    {
    case 0:
        return *chislo > rightVar.chl();
    case 1:
        return *drob > rightVar.dr();
    case 2:
        return *stroka > rightVar.str();
    }
    return false;
}

bool var::operator < (const var& rightVar)
{
    switch (num)
    {
    case 0:
        return *chislo < rightVar.chl();
    case 1:
        return *drob < rightVar.dr();
    case 2:
        return *stroka < rightVar.str();
    }
    return false;
}

bool var::operator == (const var& rightVar)
{
    switch (num)
    {
    case 0:
        return *chislo == rightVar.chl();
    case 1:
        return *drob == rightVar.dr();
    case 2:
        return *stroka == rightVar.str();
    }
    return false;
}

bool var::operator <= (const var& rightVar)
{
    return(!(*this > rightVar));
}

bool var::operator >= (const var& rightVar)
{
    return(!(*this < rightVar));
}

bool var::operator != (const var& rightVar)
{
    return(!(*this == rightVar));
}
var& var::operator =(const var& rightVar)
{
    if (this == &rightVar)
    {
        return *this;
    }
    switch (num)
    {
    case 0:
        delete chislo;
        break;
    case 1:
        delete drob;
        break;
    case 2:
        delete stroka;
        break;
    }
    num = -1;
    switch (rightVar.num)
    {
    case 0:
        chislo = new int(*(rightVar.chislo));
        break;
    case 1:
        drob = new double(*(rightVar.drob));
        break;
    case 2:
        stroka = new string(*(rightVar.stroka));
        break;
    }
    num = rightVar.num;
    return *this;
}

var& var::operator = (const int& number)
{
    switch (num)
    {
    case 0:
        delete chislo;
        break;
    case 1:
        delete drob;
        break;
    case 2:
        delete stroka;
        break;
    }
    num = 0;
    chislo = new int(number);
    return *this;
}

var& var::operator = (const double& number)
{
    switch (num)
    {
    case 0:
        delete chislo;
        break;
    case 1:
        delete drob;
        break;
    case 2:
        delete stroka;
        break;
    }
    num = 1;
    drob = new double(number);
    return *this;
}
var& var::operator = (const string& str)
{
    switch (num)
    {
    case 0:
        delete chislo;
        break;
    case 1:
        delete drob;
        break;
    case 2:
        delete stroka;
        break;
    }
    num = 2;
    stroka = new string(str);
    return *this;
}


const string operator * (const string& leftStr, const string& rightStr)
{
    string tmp;
    string::const_iterator i;
    string::const_iterator j;
    for (i = leftStr.cbegin(); i != leftStr.cend(); i++)
        for (j = rightStr.cbegin(); j != rightStr.cend(); j++)
            if (*i == *j)
            {
                tmp.push_back(*i);
                break;
            }

    return tmp;

}
const string operator / (const string& leftStr, const string& rightStr)
{
    bool flag = true;
    string tmp;
    string::const_iterator i;
    string::const_iterator j;
    for (i = leftStr.cbegin(); i != leftStr.cend(); i++)
    {
        for (j = rightStr.cbegin(); j != rightStr.cend(); j++)
        {
            if (*i == *j)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            flag = true;
            continue;
        }
        tmp.push_back(*i);
    }
    return tmp;

}
const string operator - (const string& leftStr, const string& rightStr)
{
    return leftStr;
}

void test1()
{
    var a = 10, b = "100", c;
    c = a + b;
    c.Show();       // ¬ыведет 110
    cout << "  ";
    c = b + a;
    c.Show(); // ¬ыведет У11000Ф

}

void test2()
{
    var a = "Mircl", b = "Mirror", c;
    c = a * b;
    c.Show();       // ¬ыведет УirФ
}

void test3()
{
    var a = "Nitro", b = "Glicherin", c;
    c = a / b;
    c.Show();       // ¬ыведет УerinФ

}

int main()
{
    var a = 15;
    var b = "ninga";
    var c = 7.8;
    var d = "25";
    b = a + d;
    b.Show();       // ¬ыведет 40
    if (a == b) cout << "\n good \n"; else cout << "\n bad\n";
    cout << endl;
    test1();
    cout << endl;
    test2();
    cout << endl;
    test3();
    cout << endl;
    return 0;
}