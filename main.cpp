#include <iomanip>
#include <iostream>
/*import time
def get_data() -> tuple:
    string_data_set = ["."] * (26**5)
    temp_set = [".", ".", ".", ".", "."]
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    index = 0
    for i in range(len(alphabet)):
        temp_set[4] = alphabet[i]
        for j in range(len(alphabet)):
            temp_set[3] = alphabet[j]
            for k in range(len(alphabet)):
                temp_set[2] = alphabet[k]
                for l in range(len(alphabet)):
                    temp_set[1] = alphabet[l]
                    for m in range(len(alphabet)):
                        temp_set[0] = alphabet[m]
                        string_data_set[index] = (temp_set[0] + temp_set[1] +
temp_set[2] + temp_set[3] + temp_set[4])
                        index += 1
    string_data_set.sort()
    string_data_tuple = tuple(string_data_set)
    return string_data_tuple
#standard linear search
def linear_search(data, element):
    for i in range(len(data)):
        if data[i] == element:
            return i
    return -1

#because of the way strings are stored in python we can use standard comparison operators
def binary_search(data, element):
    low = 0
    high = len(data) - 1
    while low <= high:
        mid = (low + high) // 2
        if data[mid] == element:
            return mid
        elif data[mid] < element:
            low = mid + 1
        else:
            high = mid - 1
    return -1
def timer(data, element):
    begin = time.time()
    #begin
    print(linear_search(data, element))
    end = time.time()
    lineartimer = end - begin
    #record timer
    #new timer
    begin1 = time.time()
    print(binary_search(data, element))
    end1 = time.time()
    binarytimer = end1 - begin1
    #record timer
    return [lineartimer, binarytimer]
def main():
    searchingfor = ["not_here","mzzzz","aaaaa"]
    #get data
    string_data = get_data()
    for i in searchingfor:
        result = timer(string_data, i)
        #print results
        print("Word: " + i)
        print("Linear search time: " + str(result[0]), "Binary search time: " + str(result[1]))
if __name__ == '__main__':
    main()*/
#include "stringdata.h"
int linear_search(std::vector<std::string> data, std::string element)
{
    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == element)
        {
            return i;
        }
    }
    return -1;
}
int binary_search(std::vector<std::string> data, std::string element)
{
    int low = 0;
    int high = data.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data[mid] == element)
        {
            return mid;
        }
        else if (data[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
std::vector<double> timer(std::vector<std::string> data, std::string element)
{
    auto begin = std::chrono::system_clock::now();
    //begin
    std::cout << "Linear Index: " << linear_search(data, element);
    auto end = std::chrono::system_clock::now();;
    std::chrono::duration<double> lineartimer = (end - begin);
    //record timer
    //new timer
    auto begin1 = std::chrono::system_clock::now();;
    std::cout << " Binary Index: " << binary_search(data, element);
    auto end1 = std::chrono::system_clock::now();;
    std::chrono::duration<double> binarytimer = (end1 - begin1);
    //record timer
    return std::vector<double>{lineartimer.count(), binarytimer.count()};
}
int main(){
    std::vector<std::string> my_string_data = getStringData();
    std::cout << my_string_data.size();
    std::vector<std::string> searching_for = {"not_here","mzzzz","aaaaa"};
    for (int i = 0; i < searching_for.size(); i++)
    {
        std::vector<double> result = timer(my_string_data, searching_for[i]);
        //print results
        std::cout << std::setprecision(9) << "Word: " << searching_for[i] << std::endl;
        std::cout << "Linear search time: " << result[0] << " Binary search time: " << result[1] << std::endl;
    }
}
