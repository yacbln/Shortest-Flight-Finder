
CS 225 Data Structures

Project Proposal (vasilis2-suhaasn3-quinnd2-yacineb2)

\1. **Leading Question:** Based on the OpenFlights dataset, the main target goal is to find the shortest flight path between 2 airports and highlight it in the world map.

\2. **Dataset Acquisition and Processing:**

We have chosen to use the OpenFlights routes dataset. It currently uses the .data

ﬁle extension, but will be downloaded locally to be converted into a csv/pandas

DataFrame. Once converted, it will be cleaned using pandas methods such as

df.dropna or scikit-learn FunctionTransformer methods. After cleaning, the

dataset will be hosted on GitHub.

\3. **Graph Algorithms:** We will implement BFS for Traversal and for that we need a Graph Iterator.

Then we will implement Dijkstra’s Algorithm to find the shortest path between two airports. The shortest path may or may not include stops in other airports depending if there is a direct connection between the source and destination airports. Finally, we will project the path onto a world map making use of longitude and latitude info of airports included in the path to determine their location.

The output will be a PNG that shows the shortest path. We will make use of PNG-related classes from MPs.

\4. **Timeline:**

Data cleaning - By the middle to end of next week

BFS - Implementation can start at the beginning of next week. Data doesn’t have to be completely cleaned yet for this

Dijkstra and Map projection - Will work on it during break. Hopefully finished by the end of break.


