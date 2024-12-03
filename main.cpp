
#include <iostream>
#include "graph.h"

using namespace std;
//the main provided for testing
int main()
{
    Graph g;
    try {
        string v1, v2, name;
        int choice;
        cout << "Choose one of the following:\n";
        cout << "1- to add a task\n";
        cout << "2 - to add a priority rule\n";
        cout << "3 - to print all the graph\n";
        cout << "4 - print a recommended task order\n";
        cout << "5 - exit\n";
        do
        {
            cin >> choice;
            switch (choice)
            {
                case 1:cout << "Enter the task you want to add\n";
                    cin >> v1;
                    if (!g.addv(v1)) cout << "ERROR\n";
                    break;
                case 2:cout << "Enter earlier task and the later task\n";
                    cin >> v1 >> v2;
                    if (!g.adde(v1, v2)) cout << "ERROR\n";
                    break;
                case 3:
                    cout << "The graph:\n";
                    g.printAll();
                    cout << endl;
                    break;
                case 4:
                    cout << "The recommended order:\n";
                    g.topologicalSort();
                    cout << endl;
                    break;
                case 5:cout << "byebye";  break;
                default:cout << "ERROR\n";

            }
        } while (choice != 5);
    }
    catch (string s)
    {
        cout << s << endl;
    }
    return 0;
}
/*example:
Choose one of the following:
1- to add a task
2 - to add a priority rule
3 - to print all the graph
4 - print a recommended task order
5 - exit
1
Enter the task you want to add
A
1
Enter the task you want to add
B
1
Enter the task you want to add
C
2
Enter earlier task and the later task
A B
2
Enter earlier task and the later task
B C
3
The graph:
B (1 neighbors) -> C
C (0 neighbors) ->
A (1 neighbors) -> B

4
The recommended order:
A B C

2
Enter earlier task and the later task
A C
5
byebye
Process finished with exit code 0
*/