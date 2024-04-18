using DataStructures
m = map(l -> map(x -> parse(Int, x), split(l, "")), readlines("input"))
dx = [1, -1, 0, 0]; dy = [0, 0, 1, -1]; n = length(m)
q = BinaryMinHeap{Tuple{Int, Int, Int}}()
dist = fill(typemax(Int), n, n)
push!(q, (0, 1, 1))
dist[1,1] = 0
while !isempty(q)
    (d, x, y) = pop!(q)
    if x == n && y == n
        println(d)
        exit(0)
    end
    for i in 1:4
        nx = x + dx[i]; ny = y + dy[i]
        if nx < 1 || ny < 1 || nx > n || ny > n continue end
        if d + m[ny][nx] < dist[ny,nx]
            dist[ny,nx] = d + m[ny][nx]
            push!(q, (d + m[ny][nx], nx, ny))
        end
    end
end

