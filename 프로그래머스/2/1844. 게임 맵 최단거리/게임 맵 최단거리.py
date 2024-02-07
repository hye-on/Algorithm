def solution(maps):
    n = len(maps)
    m = len(maps[0])
    dxs = [1, -1, 0, 0] # 동서남북
    dys = [0, 0, 1, -1] # 동서남북
    answer = 10001 # m,n 각각 최대 100 이기 때문에, 100*100+1 이상 타일수가 나올 수 없으므로 이 값을 max 로 잡는다.
    visit = [[False] * m for _ in range(n)]
    q = [(0, 0, 1)]
    
    while q:
        p = q.pop(0)
        x = p[0]
        y = p[1]
        num = p[2] # 지나온 타일 수
        
        if visit[y][x] == True:
            continue
        
        visit[y][x] = True
        
        for i in range(4):
            dx = dxs[i] + p[0] # x 는 열 탐색용
            dy = dys[i] + p[1] # y 는 행 탐색용

						# 유효한 인덱스만 허용 (밖으로 나가는 것 방지)
            if dx >= 0 and dy >= 0 and dx < m and dy < n:
                tile = maps[dy][dx]

								# 막혀있지 않아야 한다
                if tile == 1:
                    next_num = num + 1
                    if dx == m - 1 and dy == n - 1:
                        answer = next_num
                        break
                    else:
                        q.append((dx, dy, next_num)) # 마지막 타일이 아닌 경우 이어서 탐색
                    tile=0

    if answer == 10001:
        return -1
    
    return answer