from collections import defaultdict

class Solution:
    def survivedRobotsHealths(self, p: List[int], h: List[int], d: str) -> List[int]:
        pos_dict = defaultdict(list)
        
        # Group robots by their positions
        for pos, health, direction in zip(p, h, d):
            if direction == 'L':
                health = -health
            if pos not  in pos_dict:
                pos_dict[pos].append(health)
            else:
                pos_dict[pos].append(max(health, pos_dict[pos] if pos_dict[pos]>0 else -pos_dict[pos]) )
        st = []
        
        for pos in sorted(pos_dict.keys()):
            group = pos_dict[pos]
            group.sort(key=lambda x: abs(x))
            
            for num in group:
                count = 0
                while len(st) and (num < 0 < st[-1][1]):
                    if st[-1][1] < -num:
                        num+=1
                        st.pop()
                    elif st[-1][1] == -num:
                        st.pop()
                        break
                    elif st[-1][1] > -num:
                        tmp_pos, tmp = st.pop()
                        st.append((tmp_pos, tmp - 1))
                        break
                else:
                    st.append((pos, num))
        st_dict = {a: b for a, b in st}
        
        # Iterate over each position in p and append the corresponding value from st_dict to ans
        ans = [abs(st_dict[pos]) for pos in p if pos in st_dict]
        
        return ans
