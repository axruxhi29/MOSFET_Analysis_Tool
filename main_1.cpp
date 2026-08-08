#include <iostream>
using namespace std;

int main()
{
    double VGS, VTH, K, VDS;
    double VOV, ID, gm;

    cout << "===============================" << endl;
    cout << "   MOSFET Parameter Calculator" << endl;
    cout << "===============================\n" << endl;

    cout << "Enter value of VGS: "; //unit - V
    cin >> VGS;

    cout << "Enter value of VTH: "; //unit - V
    cin >> VTH;

    cout << "Enter value of K: "; //unit - A/V^2
    cin >> K;

    cout << "Enter value of VDS: "; //unit- V
    cin >> VDS;

    if (K < 0 || VDS < 0)
    {
     cout << "\nInvalid input!" << endl;
     return 1;
    }

    VOV = VGS - VTH;

    cout << "\n---------- Results ----------" << endl;

    cout << "VOV = " << VOV << " V" << endl;

    if (VGS <= VTH) //region checking
    {
     ID = 0;
     gm = 0;

        cout << "Region = Cutoff" << endl;
    }

    else if (VDS < VOV)
    {
        ID = K * (VOV * VDS - (VDS * VDS) / 2);  // triode region equation
        gm = K * VDS;

        cout << "Region = Triode (Linear)" << endl;
    }

    else
    {
        ID = (K / 2) * VOV * VOV; // saturation region equation
        gm = K * VOV;

        cout << "Region = Saturation" << endl;
    }

    cout << "ID = " << ID << " A" << endl;
    cout << "gm = " << gm << " S" << endl;

    cout << "-----------------------------" << endl;

    return 0;
}