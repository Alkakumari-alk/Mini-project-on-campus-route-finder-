# Mini-project-on-campus-route-finder-
Campus Route Finder

Description

Campus Route Finder is a menu-driven C program that represents campus locations as a graph and helps users explore routes between them.

Features

- Represents 8 campus locations using an adjacency list.
- Uses BFS to find the shortest route in an unweighted graph.
- Uses DFS to display reachable locations.
- Identifies locations disconnected from a selected source.
- Uses a parent array to reconstruct the BFS route.

Requirements

- C compiler such as GCC, Code::Blocks, or Dev-C++.

How to Run

1. Save the source code as "campus_route_finder.c".
2. Compile using: "gcc campus_route_finder.c -o campus_route_finder"
3. Run using: "./campus_route_finder" (on Windows, run "campus_route_finder.exe").

Complexity

BFS and DFS take O(V + E) time with an adjacency list. Their auxiliary space complexity is O(V).

Testing

Test direct routes, multi-stop routes, same-source and destination, invalid location numbers, and unreachable locations.
