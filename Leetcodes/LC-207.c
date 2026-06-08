bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    int* graphColSize = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(numCourses * sizeof(int));
    }
    // Build graph and in-degree array
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        graph[prereq][graphColSize[prereq]++] = course;
        inDegree[course]++;
    }

    // Queue for BFS
    int* queue = (int*)malloc(numCourses * sizeof(int));
    int front = 0, rear = 0;

    // Add courses with in-degree 0
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    // Process queue
    while (front < rear) {
        int current = queue[front++];
        count++;

        for (int i = 0; i < graphColSize[current]; i++) {
            int neighbor = graph[current][i];
            inDegree[neighbor]--;

            if (inDegree[neighbor] == 0) {
                queue[rear++] = neighbor;
            }
        }
    }

    return count == numCourses;
}
    
