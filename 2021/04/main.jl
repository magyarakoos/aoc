f = open("input", "r")
n::Vector{Int} = map(x -> parse(Int, x), split(readline(f), ","))
while !eof(f)
    readline(f)
    board = []
    for i in 1:5
        push!(board, map(x -> parse(Int, x), split("")))
    end
end