/**
Name: Jugal Kishore Chanda
ID: 2017-1-60-134
UnderGraduate Student
Department of Computer Science and Engineering.
East West University.
**/

#include<bits/stdc++.h>
using namespace std;
int two_r(int r)
{
    return (int)pow(2.0,(double)r);
}
int main()
{
    string str;
    cout<<"Enter The Data String with 0 and 1 ";
    getline(cin,str);
    char parity_type;
    cout<< "For even parity enter \'e\' and for odd parity enter \'o\' ";
    cin>>parity_type;
    reverse(str.begin(),str.end());
    int m = str.length();
    bool data[m+1];

    for(int i=1;i<=m;i++)
    {
        if(str[i-1] == '1'){
            data[i] = 1;
        }
        else{
            data[i] = 0;
        }
    }

    int r = 1;
    while(!((m+r+1)<=two_r(r)))
    {
        r++;
    }


    bool send_data[m+r+1];

    int p = 0;
    int d = 1;
    for(int i=1;i<=(m+r);i++)
    {
        if(i == two_r(p))
        {
            send_data[i] = 0;
            p++;
        }
        else
        {
            send_data[i] = data[d];
            d++;
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=1;j<=(m+r);j++)
        {
            if(((j>>i)&1) == 1)
            {
                if(j!=two_r(i))
                {
                    send_data[two_r(i)]^=send_data[j];

                }
            }
        }
        if(parity_type == 'o')
        {
            send_data[two_r(i)] = !(send_data[two_r(i)]);
        }
    }

    cout<<"Send Data : ";
    for(int i=(m+r);i>0;i--)
    {

        cout<<send_data[i];
    }
    cout<<"\n";


    cout<<"Enter The Receive  Data String with 0 and 1 ";
    cin.ignore();
    getline(cin,str);
    reverse(str.begin(),str.end());

    bool rece_data[m+r+1];
    for(int i=1;i<=(m+r);i++)
    {
        if(str[i-1] == '1'){
            rece_data[i] = 1;
        }
        else{
            rece_data[i] = 0;
        }
    }

    int error_position = 0;
    bool error_correction = false,temp_error = false;
    while(!error_correction)
    {
        bool temp = true;
        for(int i=0;i<r;i++)
        {
            bool parity_value = 0;
            for(int j=1;j<=(m+r);j++)
            {
                if(((j>>i)&1) == 1)
                {
                    if(j!=two_r(i))
                    {
                    parity_value^=rece_data[j];

                    }
                }
            }
            if(parity_type == 'o')
            {
                parity_value=!parity_value;
            }
            if(parity_value != rece_data[two_r(i)]){
                error_position+= two_r(i);
                temp = false;
            }

        }
        if(temp_error == true && temp == false)
        {
            cout<<"Multiple Bit Error";
            return 0;
        }
        if(temp == false)
        {
            rece_data[error_position] = !rece_data[error_position];
            temp_error = true;
        }
        else
        {
            error_correction = true;
        }
    }
    cout<<"Error Position was: "<<error_position<<endl;


    cout<<"Correct Receive Data : ";
    for(int i=(m+r);i>0;i--)
    {

        cout<<rece_data[i];
    }
    cout<<"\n";

}
