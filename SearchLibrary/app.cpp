#include"Header.h"
#include<iostream>
#include<thread>

using namespace std;

int main()
{

    FILE_SEARCHER file_searcher;

    cout << "Threads are starting to launch...";
    std::this_thread::sleep_for(1s);
    cout << "...";
    std::this_thread::sleep_for(1s);
    cout << "...";
    std::this_thread::sleep_for(1s);
    cout << "..." << endl << endl;
    std::this_thread::sleep_for(2s);

   
    //launch our's conccurent threds which works in different sub_dir

    std::thread t1(&FILE_SEARCHER::ThreadSearch1, file_searcher);

    std::thread t2(&FILE_SEARCHER::ThreadSearch2, file_searcher);

    std::thread t3(&FILE_SEARCHER::ThreadSearch3, file_searcher);

    std::thread t4(&FILE_SEARCHER::ThreadSearch4, file_searcher);

    std::thread t5(&FILE_SEARCHER::ThreadSearch5, file_searcher);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    std::this_thread::sleep_for(2s);
    cout << endl << "All Threads are finishied..." << endl;
}
