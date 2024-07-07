class Solution:
    def racecar(self, target: int) -> int:
        q = deque()
        start_pos = 0
        start_speed = 1
        step = 0
        q.append((start_pos, start_speed, step))
        visited = set()
        visited.add((start_pos, start_speed))
        while q :
            curr_pos, curr_speed, curr_step = q.popleft()
            print(curr_pos, curr_speed, curr_step)
            if curr_pos == target:
                return curr_step

            # for 'A'
            new_pos = curr_pos + curr_speed
            new_speed = 2*curr_speed
            new_step = curr_step + 1
            if (new_pos, new_speed) not in visited and abs(new_pos) <= 2*target:
                q.append((new_pos,new_speed,new_step))
                visited.add((new_pos,new_speed))

            # for 'R'
            new_pos = curr_pos 
            new_speed = -1 if curr_speed>0 else 1
            new_step = curr_step + 1
            if (new_pos, new_speed) not in visited:
                q.append((new_pos,new_speed,new_step))
                visited.add((new_pos,new_speed))
        return -1 
