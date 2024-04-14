f = open("input", "r")
n::Vector{Int} = map(x -> parse(Int, x), split(readline(f), ","))
while !eof(f)
    readline(f)
    board = []
end