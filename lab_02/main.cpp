#include <iostream>
#include "vector.hpp"

using namespace std;

int main()
{

    
    cout << "\n---Тестирование класса Vector--- \n\n";
    cout << "-  Тестирование инициализаторов  - \n";
    cout << "Проверка инициализатора без параметров: \n";
    Vector<float> v1;
    cout << "v1: " << "- пустой\n";
    
    cout << "Проверка инициализатора с колличеством элементов: \n";
    Vector<float> v2(10);
    cout << "V2: " << v2 << "\n";

    cout << "Проверка инициализатора копирования: \n";
    Vector<float> v3(v2);
    cout << "V3: " << v3 << "\n";

    cout << "Проверка инициализатора с повторяющимся элементом: \n";
    Vector<float> v4(2, 10);
    cout << "V4: " << v4 << "\n";

    cout << "Проверка инициализатора переноса: \n";
    Vector<float> v5 = Vector<float>(1, 10);
    cout << "V3: " << v5 << "\n";

    cout << "\n\n- Тестирование методов - \n\n";
    Vector<float> temp;

    cout << "Проверка оператора +\n";
    cout << "V2 = " << v2 << "\n";
    cout << "V4 = " << v4 << "\n";
    temp = v2 + v4;
    cout << "V2 + V4 = " << temp << "\n";
    
    cout << "\nПроверка метода addVector()\n";
    cout << "V2 = " << v2 << "\n";
    cout << "V4 = " << v4 << "\n";
    temp = v2.addVector(v4);
    cout << "V2.addVector(V4) = " << temp << "\n";

    cout << "\nПроверка оператора +=\n";
    cout << "V2 = " << v2 << "\n";
    cout << "V4 = " << v4 << "\n";
    v2 += v4;
    cout << "V2 += V4 = " << v2 << "\n";

    cout << "\nПроверка метода addVectorAssign()\n";
    cout << "V2 = " << v2 << "\n";
    cout << "V4 = " << v4 << "\n";
    v2.addVectorAssign(v4);
    cout << "V2.addVectorAssign(V4) = " << v2 << "\n";

    cout << "\nПроверка оператора -\n";
    cout << "V2 = " << v2 << "\n";
    cout << "V4 = " << v4 << "\n";
    temp = v2 - v4;
    cout << "V2 - V4 = " << temp << "\n";

    cout << "\nПроверка метода substractVector()\n";
    cout << "V2 = " << v2 << "\n";
    cout << "V4 = " << v4 << "\n";
    temp = v2.substractVector(v4);
    cout << "V2.substractVector(V4) = " << temp << "\n";

    cout << "\nПроверка оператора -=\n";
    cout << "V2 = " << v2 << "\n";
    cout << "V4 = " << v4 << "\n";
    v2 -= v4;
    cout << "V2 -= V4 = " << v2 << "\n";

    cout << "\nПроверка метода substractVectorAssign()\n";
    cout << "V2 = " << v2 << "\n";
    cout << "V4 = " << v4 << "\n";
    v2.substractVectorAssign(v4);
    cout << "V2.substractVectorAssign(V4) = " << v2 << "\n";

    v2 += v4;
    cout << "\nПроверка оператора *\n";
    cout << "V2 = " << v2 << "\n";
    cout << "V4 = " << v4 << "\n";
    int tempInt = v2 * v4;
    cout << "V2 * V4 = " << tempInt << "\n";

    cout << "\nПроверка метода dotProduct()\n";
    cout << "V2 = " << v2 << "\n";
    cout << "V4 = " << v4 << "\n";
    tempInt = v2.dotProduct(v4);
    cout << "V2.dotProduct(V4) = " << tempInt << "\n";

    cout << "\nПроверка оператора *\n";
    cout << "V2 = " << v2 << "\n";
    v2 = v2 * 2.;
    cout << "V2 * 2 = " << v2 << "\n";

    cout << "\nПроверка метода multiplyBy()\n";
    cout << "V2 = " << v2 << "\n";
    v2 = v2.multiplyBy(2.);
    cout << "V2.multiplyBy(2) = " << v2 << "\n";

    cout << "\nПроверка оператора *=\n";
    cout << "V2 = " << v2 << "\n";
    v2 *= 2.;
    cout << "V2 *= 2 = " << v2 << "\n";

    cout << "\nПроверка метода multiplyByAssign()\n";
    cout << "V2 = " << v2 << "\n";
    v2.multiplyByAssign(2.);
    cout << "V2.multiplyByAssign(2) = " << v2 << "\n";

    cout << "\nПроверка оператора /\n";
    cout << "V2 = " << v2 << "\n";
    v2 = v2 / 2.;
    cout << "V2 / 2 = " << v2 << "\n";

    cout << "\nПроверка метода divideBy()\n";
    cout << "V2 = " << v2 << "\n";
    v2 = v2.divideBy(2.);
    cout << "V2.divideBy(2) = " << v2 << "\n";

    cout << "\nПроверка оператора /=\n";
    cout << "V2 = " << v2 << "\n";
    v2 /= 2.;
    cout << "V2 /= 2 = " << v2 << "\n";

    cout << "\nПроверка метода divideByAssign()\n";
    cout << "V2 = " << v2 << "\n";
    v2.divideByAssign(2);
    cout << "V2.divideByAssign(2) = " << v2 << "\n";

    Vector<float> va1({1, 0});
    Vector<float> va2({0, 1});

    cout << "\nПроверка оператора !=\n";
    cout << "VA1 = " << va1 << "\n";
    cout << "VA2 = " << va2 << "\n";
    if (va1 != va2)
        cout<<"VA1 и VA2 не равны\n";
    else
        cout << "VA1 и VA2 Равны\n";
        
    cout << "\nПроверка метода angleBetween()\n";
    cout << "VA1 = " << va1 << "\n";
    cout << "VA2 = " << va2 << "\n";
    cout << "va1.angleBetween(va2) = " << va1.angleBetween(va2) << "\n";

    cout << "\nПроверка метода isCollinear()\n";
    cout << "VA1 = " << va1 << "\n";
    cout << "va1.isCollinear(va1) = " << va1.isCollinear(va1) << "\n";

    cout << "\nПроверка метода isOrthogonal()\n";
    cout << "VA1 = " << va1 << "\n";
    cout << "VA2 = " << va2 << "\n";
    cout << "va1.isOrthogonal(va2) = " << va1.isOrthogonal(va2) << "\n";

    cout << "\nПроверка метода length()\n";
    cout << "V2 = " << v2 << "\n";
    cout << "v2.length() = " << v2.length() << "\n";

    cout << "\nПроверка метода normalize()\n";
    cout << "V2 = " << v2 << "\n";
    cout << "v2.normalize() = " << v2.normalize() << "\n";

    cout << "\nПроверка clear(): " << "\n";
    v2.clear();
    if (v2.isEmpty())
        cout << "V2 - пустой \n";

    Vector<int> vt({0,0,0});
    try
    {
        vt.normalize();
    }        
    catch (BaseException &err)
    {
        cout << err.what() << endl;
    }

    return 0;
} 