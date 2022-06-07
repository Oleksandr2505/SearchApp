#pragma once
#include<iostream>
#include <filesystem>
#include<thread>
#include<mutex>

namespace fs = std::filesystem;

class FILE_SEARCHER
{
public:
    void get_num_of_files_recursively_for(fs::path sub_dir);
    void ThreadSearch1();
    void ThreadSearch2();
    void ThreadSearch3();
    void ThreadSearch4();
    void ThreadSearch5();


};

