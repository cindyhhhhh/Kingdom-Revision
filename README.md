# Kingdom-Revision

Problem Description:

This is the ADA kingdom again!!! YP is the king of the ADA kingdom, and his responsibility (and his interest) is to protect the kingdom. The ADA kingdom has n cities connected by n − 1 bi-directional roads. Each road has an importance value. It is guaranteed that for any two cities, there exist a sequence of roads such that one can move from one city to the other city, by walking along these roads.
There are k soldiers in the military. YP would like to allocate these soldiers to the cities to protect the roads. A road is defined as protected if there exist two soldiers such that one of the soldiers must pass through this road in order to arrive in the city guarded by the other soldier.
Please help YP allocate soldiers so that the sum of importance values over all protected roads is maximized.


Input:

The first line contains an integer n (2 ≤ n ≤ 5 × 10^5), indicating the number of cities in the ADA kingdom. In the next n − 1 lines, each line contains three integers u,v,d (1 ≤ u,v ≤ n,1 ≤ d ≤ 10^9), indicating that there exists a road connecting cities u and v with an importance value d.


Output:

The output should contain n integers, the k-th of which represents the maximum sum of the importance values of all protected roads if there are k soldiers in the military. K starts from 1.
