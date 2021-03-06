#include "../inc/MyClass.h"
#include <map>

#include <iostream>
#include <string>

int main() {

    serializer::stream os;          // stream to be sent
    serializer::oarchive oa(os); // serializer in charge of serializing

    double id = -1.156;
    std::string str{"This is a sentence"};
    std::unordered_set<double> myUSet{15.516505, 1.56156156, 56.30501505};
    //std::map<int, float> myMap = {{5, 5.3543}, {3, 1.3423}, {7, 9.23423}};
    std::map<char, std::set<int>> myMap = {{'f', {3, 5,  34, 3}},
                                           {'d', {5, 67, 4}},
                                           {'j', {5, 67, 34}}};
    MyClass ins;
    ins.e1 = {1, 2, 3, 4, 5};
    ins.e2 = {6, 7, 8, 9, 10};
    ins.e3 = "This is a whole sentence";
    std::set<double> mySet{15.516505, 1.56156156, 56.30501505};
    std::queue<float> myQueue;
    myQueue.push(15.516505);
    myQueue.push(1.56156156);
    myQueue.push(56.30501505);
    std::list<float> myList{15.516505, 1.56156156, 56.30501505};

    // serializer into the stream *****************************
    //oa << ins;

    //return 0;
    //oa << id << str << myMap;
    oa << id;
    oa << str;
    oa << myMap;
    oa << ins;
    oa << mySet;
    oa << myQueue;
    oa << myList;
    // ***********************************************************
    serializer::stream is(os);      // stream to received bytes
    serializer::iarchive ia(is); // serializer in charge of deserializing

    double id_received;
    std::string str_received;
    std::map<char, std::set<int>> myMap_received;
    MyClass ins_received;
    std::set<double> mySet_received;
    std::queue<float> myQueue_received;
    std::list<float> myList_received;

    // deserialization from stream ***************************

    ia >> id_received;
    ia >> str_received;
    ia >> myMap_received;
    ia >> ins_received;
    ia >> mySet_received;
    ia >> myQueue_received;
    ia >> myList_received;
    //ia >> id_received >> str_received;
    // ***********************************************************


    std::string b = id == id_received ? "true" : "false";
    std::cout << "id successfully deserialized : " << b << "\n";
    b = myMap == myMap_received ? "true" : "false";
    std::cout << "myMap successfully deserialized : " << b << "\n";
    b = mySet == mySet_received ? "true" : "false";
    std::cout << "mySet successfully deserialized : " << b << "\n";
    b = myList == myList_received ? "true" : "false";
    std::cout << "myList successfully deserialized : " << b << "\n";
    b = ins == ins_received ? "true" : "false";
    std::cout << "ins successfully deserialized : " << b << "\n";
    return 0;
}