D - XOR Shortest Walk  / 
Time Limit: 2 sec / Memory Limit: 1024 MiB

Score : 
400 points

Problem Statement
There is a directed graph with 
N vertices and 
M edges, where vertices are numbered from 
1 to 
N and edges are numbered from 
1 to 
M. Edge 
i is a directed edge from vertex 
A 
i
​
  to vertex 
B 
i
​
  with weight 
W 
i
​
 .

Find the minimum value of the bitwise 
XOR of the weights of edges included in a walk from vertex 
1 to vertex 
N.

What is a walk from vertex 
1 to vertex 
N?
What is the bitwise 
XOR operation?
Constraints
2≤N≤1000
0≤M≤1000
1≤A 
i
​
 ,B 
i
​
 ≤N
0≤W 
i
​
 <2 
10
 
All input values are integers.
Input
The input is given from Standard Input in the following format:

N 
M
A 
1
​
  
B 
1
​
  
W 
1
​
 
A 
2
​
  
B 
2
​
  
W 
2
​
 
⋮
A 
M
​
  
B 
M
​
  
W 
M
​
 
Output
If there is no walk from vertex 
1 to vertex 
N, output -1.

If there is a walk from vertex 
1 to vertex 
N, output the minimum value of the bitwise 
XOR of the weights of edges included in such a walk.

Sample Input 1
Copy
3 3
1 2 4
2 3 5
1 3 2
Sample Output 1
Copy
1
The bitwise 
XOR of the weights of edges included in the walk (edge 
1, edge 
2) is 
1.

Sample Input 2
Copy
4 4
1 4 7
4 2 2
2 3 4
3 4 1
Sample Output 2
Copy
0
The bitwise 
XOR of the weights of edges included in the walk (edge 
1, edge 
2, edge 
3, edge 
4) is 
0.

Note that the walk may include vertex 
N in the middle.

Sample Input 3
Copy
999 4
1 2 9
2 1 8
1 2 7
1 1 6
Sample Output 3
Copy
-1
If there is no walk from vertex 
1 to vertex 
N, output -1.