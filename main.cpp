#include <iostream>
#include <vector>

using namespace std;

class SET
{
public:
    vector<int> elements;

    int findPosition(int data) const
    {
        int left = 0;
        int right = elements.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (elements[mid] == data)
            {
                return -1; 
            }
            else if (elements[mid] < data)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left; 
    }

    void insertElementAt(int pos, int data)
    {
        elements.push_back(0);
        for (int i = elements.size() - 1; i > pos; --i)
        {
            elements[i] = elements[i - 1];
        }
        elements[pos] = data;
    }

    void removeElementAt(int pos)
    {
        for (int i = pos; i < elements.size() - 1; ++i)
        {
            elements[i] = elements[i + 1];
        }
        elements.pop_back();
    }

    int binary_search(const std::vector<int> &arr, int target)
    {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
            {
                return mid;
            }
            else if (arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }

public:
    void commands(int command, int data, SET &set_2)
    {
        
        switch (command)
        {
        case 1:
        { // Insert
            int pos = findPosition(data);
            if (pos != -1)
            {
                insertElementAt(pos, data);
            }
            cout << elements.size() << endl;
            break;
        }
        case 2:
        { // Delete
            int pos = binary_search(elements, data);

            if (pos == -1)
            {
                cout << elements.size() << endl; // Element doesn't exist in the set
            }
            else
            {
                removeElementAt(pos);
                cout << elements.size() << "\n";
            }
            break;
        }
        case 3:
        { // Belongs To
            int pos = binary_search(elements, data);
            if (pos == -1)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
            break;
        }
        case 4:
        { // Union

            vector<int> result;
            auto &set1 = elements;
            auto &set2 = set_2.elements;
            int i = 0, j = 0;
            while (i < set1.size() && j < set2.size())
            {
                if (set1[i] < set2[j])
                {
                    result.push_back(set1[i++]);
                }
                else if (set1[i] > set2[j])
                {
                    result.push_back(set2[j++]);
                }
                else
                {
                    result.push_back(set1[i++]);
                    j++;
                }
            }
            while (i < set1.size())
            {
                result.push_back(set1[i++]);
            }
            while (j < set2.size())
            {
                result.push_back(set2[j++]);
            }
            elements = result;
            cout << result.size() << "\n";
            break;
        }
        case 5:
        { // Intersection
            vector<int> result;
            auto &set1 = elements;
            auto &set2 = set_2.elements;
            int i = 0, j = 0;
            while (i < set1.size() && j < set2.size())
            {
                if (set1[i] < set2[j])
                {
                    i++;
                }
                else if (set1[i] > set2[j])
                {
                    j++;
                }
                else
                {
                    result.push_back(set1[i++]);
                    j++;
                }
            }
            elements = result;
            cout << result.size() << "\n";
            break;
        }
        case 6:
        { // Size
            cout << elements.size() << "\n";
            break;
        }
        case 7:
        { // Difference
            vector<int> result;
            auto &set1 = elements;
            auto &set2 = set_2.elements;
            int i = 0, j = 0;
            while (i < set1.size() && j < set2.size())
            {
                if (set1[i] < set2[j])
                {
                    result.push_back(set1[i++]);
                }
                else if (set1[i] > set2[j])
                {
                    j++;
                }
                else
                {
                    i++;
                    j++;
                }
            }
            while (i < set1.size())
            {
                result.push_back(set1[i++]);
            }
            elements = result;
            cout << result.size() << "\n";
            break;
        }
        case 8:
        { // Symmetric Difference
            vector<int> result;
            auto &set1 = elements;
            auto &set2 = set_2.elements;
            int i = 0, j = 0;
            while (i < set1.size() && j < set2.size())
            {
                if (set1[i] < set2[j])
                {
                    result.push_back(set1[i++]);
                }
                else if (set1[i] > set2[j])
                {
                    result.push_back(set2[j++]);
                }
                else
                {
                    i++;
                    j++;
                }
            }
            while (i < set1.size())
            {
                result.push_back(set1[i++]);
            }
            while (j < set2.size())
            {
                result.push_back(set2[j++]);
            }
            elements = result;
            cout << result.size() << "\n";
            break;
        }
        case 9:
        { // Print
            for (int i = 0; i < elements.size(); ++i)
            {
                cout << elements[i];
                if (i != elements.size() - 1)
                {
                    cout << ",";
                }
            }
            cout << "\n";
            break;
        }
        default:
            break;
        }
    }

    
};

void createSets(int set1num, std::vector<SET> &mycollection, int set2num = -1)
{
    if (set1num >= mycollection.size() || set2num >= mycollection.size())
    {
        if (set1num >= mycollection.size())
        {
            SET a;
            mycollection.push_back(a);
        }

        if (set2num != -1 && set2num >= mycollection.size())
        {
            SET a;
            mycollection.push_back(a);
        }
    }
}

int main()
{
    
    vector<SET> mycollection;
    int command;
    int set1num;
    int third;
    while (cin >> command)
    {
        cin >> set1num;
        if (command == 9)
        {
            if (set1num >= mycollection.size())
            {
                cout << endl;
                continue;
            }
            mycollection[set1num].commands(9, 0, mycollection[0]);
        }
        else if (command == 6)
        {
            createSets(set1num, mycollection);
            mycollection[set1num].commands(6, 0, mycollection[0]);
        }
        else if (command == 2)
        {
            cin >> third;
            if (set1num >= mycollection.size())
            {
                cout << -1 << endl;
                continue;
            }
            mycollection[set1num].commands(2, third, mycollection[0]);
        }
        else if (command == 4 || command == 5 || command == 7 || command == 8)
        {
            cin >> third;
            createSets(set1num, mycollection, third);
            mycollection[set1num].commands(command, 0, mycollection[third]);
        }
        else if (command == 1)
        {
            createSets(set1num, mycollection);
            cin >> third;
            mycollection[set1num].commands(command, third, mycollection[0]);
        }
        else if (command == 3)
        {
            cin >> third;
            if (set1num >= mycollection.size())
            {
                cout << -1 << endl;
                continue;
            }
            mycollection[set1num].commands(command, third, mycollection[0]);
        }
    }
    return 0;
}