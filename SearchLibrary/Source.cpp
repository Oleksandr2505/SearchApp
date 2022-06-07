#include"Header.h"
#include<thread>


    using namespace std;
    using namespace ::filesystem;
    
    //include sub-dir where we want to find a file
    fs::path wayToFile1{ "C:\\xampp" };
    fs::path wayToFile2{ "C:\Windows10Upgrade" };
    fs::path wayToFile3{ "C:\Windows" };
    fs::path wayToFile4{ "C:\ProgramData" };
    fs::path wayToFile5{ "C:\OpenSSH" };
    const fs::path file_name = "xampp_start.exe";
    mutex mutex_process;


    void FILE_SEARCHER::get_num_of_files_recursively_for(fs::path sub_dir)
    {
        int num = 0;
        
        //count amount of files in current directory
        if (fs::is_directory(sub_dir)) {
            for (fs::recursive_directory_iterator it(
                sub_dir, fs::directory_options::skip_permission_denied);
                it != fs::recursive_directory_iterator(); ++it) {
                num++;
            }
            cout << "Number of files in current directory: " << num << endl;
            cout << "----------------------------------" << endl;


            for (const auto& entry : fs::directory_iterator(sub_dir)) {

                std::cout << entry.path() << std::endl;
                cout << "------------------------------------" << endl;
            }
        }
        else {
            std::cout << "Entered path is not a directory ! \nPlease write the path one more time!" << endl;;

        }

    }

    void FILE_SEARCHER::ThreadSearch1()
    {
        
        //go through directyry by iterator
        using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

        auto d = fs::directory_iterator(wayToFile1);
       
        //through lambda and count if go through all files and compare with our filename
        auto found = std::find_if(begin(d), end(d), [](const auto& dir_entry)
        {
                if (dir_entry.path().filename() == file_name) {
                    cout << "in directory " << wayToFile2 << endl;
           
                }

                return dir_entry.path().filename() == file_name;
        });

       
        //checking either thread has found current file or not
        if (found != end(d))
        {
            
            cout << "file was found by thread 1 ! " << endl << "The name of file is" << file_name << endl;
            if (path().filename() == file_name)
                cout << wayToFile1 << endl;

            std::this_thread::sleep_for(2s);
            cout << endl << "Counting amount of files in this current directory..." << endl << endl;
            std::this_thread::sleep_for(2s);
            get_num_of_files_recursively_for(wayToFile1);
        }
    //we repeat all this in other functions
    }

    void FILE_SEARCHER::ThreadSearch2() {

        using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;

        auto d = fs::directory_iterator(wayToFile2);
        auto found = std::find_if(begin(d), end(d), [](const auto& dir_entry)
        {
                if (dir_entry.path().filename() == file_name) {
                    cout << "in directory " << wayToFile2 << endl;
                }

                return dir_entry.path().filename() == file_name;
        });


        if (found != end(d))
        {
           
            cout << "file was found by thread 2 ! " << endl << "The name of file is" << file_name << endl;
            if (path().filename() == file_name)
                cout << wayToFile2 << endl;

            std::this_thread::sleep_for(2s);
            cout << endl << "Counting amount of files in this current directory..." << endl << endl;
            std::this_thread::sleep_for(2s);
            get_num_of_files_recursively_for(wayToFile2);
        }
        
    }

    void FILE_SEARCHER::ThreadSearch3() 
    {

        using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
        auto d = fs::directory_iterator(wayToFile3);
        
        auto found = std::find_if(begin(d), end(d), [](const auto& dir_entry)
        {
                if (dir_entry.path().filename() == file_name) {
                    cout << "in directory " << wayToFile3 << endl;
                
                }

                return dir_entry.path().filename() == file_name;
        });

        if (found != end(d))
        {
           
            cout << "file was found by thread 3 ! " << endl << "The name of file is" << file_name << endl;
            if (path().filename() == file_name)
                cout << wayToFile3 << endl;

            std::this_thread::sleep_for(2s);
            cout << endl << "Counting amount of files in this current directory..." << endl << endl;
            std::this_thread::sleep_for(2s);
            get_num_of_files_recursively_for(wayToFile3);
        }
    
    }

    void FILE_SEARCHER::ThreadSearch4() {
        using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
        auto d = fs::directory_iterator(wayToFile4);

        auto found = std::find_if(begin(d), end(d), [](const auto& dir_entry)
        {
                if (dir_entry.path().filename() == file_name) {
                    cout << "in directory " << wayToFile4 << endl;
               
                }

                return dir_entry.path().filename() == file_name;
        });

        if (found != end(d))
        {
            
            cout << "file was found by thread 4 ! " << endl << "The name of file is" << file_name << endl;
            if (path().filename() == file_name)
                cout << wayToFile4 << endl;

            std::this_thread::sleep_for(2s);
            cout << endl << "Counting amount of files in this current directory..." << endl << endl;
            std::this_thread::sleep_for(2s);
            get_num_of_files_recursively_for(wayToFile4);
        }
        
     
    }
    void FILE_SEARCHER::ThreadSearch5() {

        using recursive_directory_iterator = std::filesystem::recursive_directory_iterator;
        auto d = fs::directory_iterator(wayToFile5);

        auto found = std::find_if(begin(d), end(d), [](const auto& dir_entry)
        {
                if (dir_entry.path().filename() == file_name) {
                    cout << "in directory " << wayToFile5 << endl;
                
                }
                return dir_entry.path().filename() == file_name;
        });

        if (found != end(d))
        {
          
            cout << "file was found by thread 5 ! " << endl << "The name of file is" << file_name << endl;
            if (path().filename() == file_name)
                cout << wayToFile5 << endl;
            std::this_thread::sleep_for(2s);

            cout << endl << "Counting amount of files in this current directory..." << endl << endl;
            std::this_thread::sleep_for(2s);
            get_num_of_files_recursively_for(wayToFile5);
        }
        

    }

