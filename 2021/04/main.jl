f = open("input", "r")
n::Vector{Int} = map(x -> parse(Int, x), split(readline(f), ","))
b = []
while !eof(f)
    readline(f)
    board = []
    for i in 1:5
        push!(board, map(x -> parse(Int, x), split(readline(f))))
    end
    push!(b, board)
end
bc = zeros(Int, length(b), 10)
for x in n
    for i in eachindex(b), j in 1:5, k in 1:5
        if b[i][j][k] == x
            bc[i, j] += 1
            bc[i, k + 5] += 1
        end
    end
end