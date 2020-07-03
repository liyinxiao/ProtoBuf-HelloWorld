#include "hello.pb.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
bool writeBuf(string file_path)
{
    lm::helloworld msg1;
    lm::helloworld::PhoneNumber *phone;
    msg1.set_id(100);
    msg1.set_str("200");

    phone = msg1.add_phones();
    phone->set_number("12345");
    phone->set_type(lm::helloworld_PhoneType_HOME);


    fstream output(file_path, ios::out | ios::trunc | ios::binary);

    if (!msg1.SerializeToOstream(&output)) {
        cerr << "Failed to write msg." << endl;
        return false;
    }
    return true;
}

void ListMsg(const lm::helloworld & msg) {
    cout << msg.id() << endl;
    cout << msg.str() << endl;
    for (int i =0; i<msg.phones_size(); i++)
    {

        cout << msg.phones(i).number() << endl;
    }
}

bool readBuf(string file_path)
{
    lm::helloworld msg1;
    {
        fstream input(file_path, ios::in | ios::binary);
        if (!msg1.ParseFromIstream(&input)) {
            cerr << "Failed to parse address book." << endl;
            return -1;
        }
    }
    ListMsg(msg1);
}

int main()
{
    string path = "./test_data.log";
    writeBuf(path);
    readBuf(path);
    return 0;
}
