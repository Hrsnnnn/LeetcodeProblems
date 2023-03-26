from typing import List
import heapq

class Solution:
    def getOrder_Slow(self, tasks: List[List[int]]):
        current_time = min(tasks, key=lambda x: x[0])[0]
        sorted_task = sorted(enumerate(tasks), key=lambda x: (x[1][1], x[0]))
        print(sorted_task)
        res = []

        while len(sorted_task) > 0:
            min_time = min(tasks, key=lambda x: x[0])[0]
            current_time = max(current_time, min_time)
            for idx, t in enumerate(sorted_task):
                if t[1][0] <= current_time:
                    current_time += t[1][1]
                    res.append(t[0])
                    break
            sorted_task = sorted_task[:idx] + sorted_task[idx+1:]
            print(sorted_task, res)
        return res
    
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        res = []
        tasks = sorted([(t[0], t[1], i) for i, t in enumerate(tasks)])
        i = 0
        h = []
        time = tasks[0][0]
        while len(res) < len(tasks):
            while (i < len(tasks)) and (tasks[i][0] <= time):
                heapq.heappush(h, (tasks[i][1], tasks[i][2])) # (processing_time, original_index)
                i += 1
            if h:
                t_diff, original_index = heapq.heappop(h)
                time += t_diff
                res.append(original_index)
            elif i < len(tasks):
                time = tasks[i][0]
        return res

if __name__ == '__main__':
    testcases = [
        [[1,2],[2,4],[3,2],[4,1]],
        [[7,10],[7,12],[7,5],[7,4],[7,2]],
        [[19,13],[16,9],[21,10],[32,25],[37,4],[49,24],[2,15],[38,41],[37,34],[33,6],[45,4],[18,18],[46,39],[12,24]]
    ]
    sol = Solution()
    for t in testcases:
        res = sol.getOrder(t)
        print('result', res)
